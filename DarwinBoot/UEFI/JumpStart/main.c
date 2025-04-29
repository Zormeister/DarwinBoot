// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "Platform/EFI/Protocols/DevicePath.h"
#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFITypes.h>

#define DBOD_PATH WSTRING("\\System\\Library\\CoreServices\\boot.efi")
#define DBOL_PATH WSTRING("\\EFI\\DarwinBoot\\DarwinBoot.efi")

/* TODO: this. */
EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable) {
    if (CDBInitializeUEFI(Handle, SystemTable)) {
        CDBLog("[JS][M]: hello");
        EFI_DEVICE_PATH_PROTOCOL *Path = LIP->FilePath;
        CDBLog("[JS][M]: PathType: %d SubType: %d", Path->Type, Path->SubType);
        panic("[JS]: I need this so I can see my results");
    }
    return 0;
}
