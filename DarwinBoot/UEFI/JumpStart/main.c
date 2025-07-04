// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "CoreDarwinBoot/CDBBasicTypes.h"
#include "Platform/EFI/Protocols/DevicePath.h"
#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>

#define DBOD_PATH WSTRING("\\System\\Library\\CoreServices\\boot.efi")
#define DBOL_PATH WSTRING("\\EFI\\DarwinBoot\\DarwinBoot.efi")

extern EFI_STATUS LoadNextLoader(EFI_DEVICE_PATH_PROTOCOL *DevicePath);

/* TODO: this. */
EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable) {
    if (EFIInitialize(Handle, SystemTable)) {
        CDBLog("[JS][M]: hello");
        EFI_DEVICE_PATH_PROTOCOL *Path = LIP->FilePath;
        CDBLog("[JS][M]: PathType: %d SubType: %d", Path->Type, Path->SubType);
        if (Path->Type == 4 && Path->SubType == EFI_MEDIA_PATH_SUBTYPE_FILE_PATH) {
            EFI_DEVICE_PATH_MEDIA_FILE_PATH_PROTOCOL *DP = (EFI_DEVICE_PATH_MEDIA_FILE_PATH_PROTOCOL *)Path;
            ST->ConOut->OutputString(ST->ConOut, DP->Path);
            ST->ConOut->OutputString(ST->ConOut, WSTRING("\r\n"));
        }
        panic("stall");
        return LoadNextLoader(LIP->FilePath);
    }
    return 0;
}
