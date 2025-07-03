// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>

#define ONDISK_PATH WSTRING("\\System\\Library\\CoreServices\\boot.efi")
#define ONESP_PATH  WSTRING("\\EFI\\DarwinBoot\\DarwinBoot.efi")

EFI_STATUS LoadNextLoader(EFI_DEVICE_PATH_PROTOCOL *DevicePath) {
    wchar_t *NextLoaderFullPath;
    /* Decode DevicePath */
    switch (DevicePath->Type) {
        case EFI_DEVICE_PATH_TYPE_MEDIA_DEVICE:
            switch (DevicePath->SubType) {
                case EFI_MEDIA_PATH_SUBTYPE_FILE_PATH: {
                    EFI_DEVICE_PATH_MEDIA_FILE_PATH_PROTOCOL *FilePath = (EFI_DEVICE_PATH_MEDIA_FILE_PATH_PROTOCOL *)DevicePath;
                    
                    
                    return EFI_SUCCESS;
                }
            }
        default:
            panic("JS: well this is awkward (DevicePath isn't a Media path. Start worrying.)");
    }

    //BS->LoadImage(false, LIP, NULL, NULL, 0, NULL);

    return EFI_SUCCESS;
    /* ^ We hopefully shouldn't return here. Flow of execution should be transferred to the next stage. */
}
