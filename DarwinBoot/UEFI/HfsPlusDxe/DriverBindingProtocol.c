// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Platform/Apple/HFS/Types/VolumeHeader.h>
#include <Platform/EFI/Protocols/DriverBinding.h>
#include <Platform/EFI/EFI.h>
#include <stdlib.h>

EFI_GUID gAppleHfsPartitionGuid = {0x48465300, 0x0000, 0x11AA, {0xAA, 0x11, 0x00, 0x30,0x65, 0x43, 0xEC, 0xAC}};

EFI_STATUS HfsPlusDriverBindingSupported(EFI_DRIVER_BINDING_PROTOCOL *This, EFI_HANDLE ControllerHandle, EFI_DEVICE_PATH_PROTOCOL *DP) {
    EFI_BLOCK_IO_PROTOCOL *BlkIO = NULL;
    EFI_PARTITION_INFO_PROTOCOL *PartitionInfo = NULL;
    EFI_STATUS status = EFI_SUCCESS;

    status = BS->OpenProtocol(ControllerHandle, &gEfiBlockIoProtocolGuid, (void **)&BlkIO, 
                                This->DriverBindingHandle, ControllerHandle, EFI_OPEN_PROTOCOL_BY_DRIVER);
    if (status) {
        /* No EFI block I/O. */
        BS->CloseProtocol(ControllerHandle, &gEfiBlockIoProtocolGuid, This->DriverBindingHandle, ControllerHandle);
        return EFI_UNSUPPORTED;
    }

    /* Additionally, check that the drive has an HFS+ GUID. */
    status = BS->OpenProtocol(ControllerHandle, &gEfiPartitionInfoProtocolGuid, (void **)&PartitionInfo, 
                                This->DriverBindingHandle, ControllerHandle, EFI_OPEN_PROTOCOL_BY_DRIVER);

    if (status) {
        goto read_volume_header;
    }

    if (PartitionInfo->Type == PARTITION_TYPE_GPT) {
        /* riddle me this clang: if PartitionGUID is the first field, how could it be misaligned?  */
        /* EFI_PARTITION_INFO_PROTOCOL is literally aligned how x86 likes it. */
        if (EFIGuidMatches(&PartitionInfo->Info.GPT.PartitionGUID, &gAppleHfsPartitionGuid)) {
            BS->CloseProtocol(ControllerHandle, &gEfiPartitionInfoProtocolGuid, This->DriverBindingHandle, ControllerHandle);
        } else {
            BS->CloseProtocol(ControllerHandle, &gEfiPartitionInfoProtocolGuid, This->DriverBindingHandle, ControllerHandle);
            BS->CloseProtocol(ControllerHandle, &gEfiBlockIoProtocolGuid, This->DriverBindingHandle, ControllerHandle);
            return EFI_UNSUPPORTED;
        }
    }

read_volume_header:
    /* Even if the GUIDs are the same, make sure the block header is actually an HFS+ header. */

    /* Allocate a buffer of 2048 so I can get the header after the offset. */
    void *buffer = malloc(2048);
    BlkIO->ReadBlocks(BlkIO, BlkIO->Media->MediaID, 0, 2048, buffer);

    HFSVolumeHeader *VH = (HFSVolumeHeader *)(buffer + kHFSVolumeHeaderOffset);
    status = EFI_UNSUPPORTED;
    if (VH->Signature == kHFSPlusSigWord || VH->Signature == kHFSXSigWord) {
        status = EFI_SUCCESS;
    }

    free(buffer);
    BS->CloseProtocol(ControllerHandle, &gEfiBlockIoProtocolGuid, This->DriverBindingHandle, ControllerHandle);

    return status;
}

EFI_DRIVER_BINDING_PROTOCOL gHfsPlusDxeDriverBindingProtocol = {
    &HfsPlusDriverBindingSupported,
    NULL,
    NULL,
    0x10,
    NULL,
    NULL,
};
