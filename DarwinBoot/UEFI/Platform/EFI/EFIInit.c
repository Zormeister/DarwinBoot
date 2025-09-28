// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/LoadedImage.h>

EFI_SYSTEM_TABLE *ST = NULL;
EFI_BOOT_SERVICES *BS = NULL;
EFI_RUNTIME_SERVICES *RT = NULL;
EFI_HANDLE IH = NULL;
EFI_LOADED_IMAGE_PROTOCOL *LIP = NULL;

// don't startup filesystem services in DXEs, it'd be a waste of resources (and time). 
// corecryptodxe + hfsplusdxe shouldn't need to access filesystems
#define INIT_FILESYSTEM_SERVICES !UEFI_DXE

bool EFIInitialize(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_GUID LoadedImageProtocol = EFI_LOADED_IMAGE_PROTOCOL_GUID;

    /* we can't exactly scream for help right now, */
    if (SystemTable->Header.Signature != EFI_SYSTEM_TABLE_SIGNATURE) {
        return false;
    }
    if (SystemTable->BootServices == NULL || SystemTable->RuntimeServices == NULL || SystemTable->ConOut == NULL) {
        return false;
    }
    // init table vars
    ST = SystemTable;
    BS = SystemTable->BootServices;
    RT = SystemTable->RuntimeServices;
    /* should i even bother to verify the integrity of the system table */
    SystemTable->ConOut->Reset(SystemTable->ConOut, false);
    IH = ImageHandle;
    BS->HandleProtocol(ImageHandle, &LoadedImageProtocol, (void **)&LIP);
    return true;
}
