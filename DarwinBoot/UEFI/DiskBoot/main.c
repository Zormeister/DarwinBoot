// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Platform/EFI/EFI.h>
#include <CoreDarwinBoot/CoreDarwinBoot.h>

/* TODO: this. */
EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable) {
    if (EFIInitialize(Handle, SystemTable)) {
        CDBLog("[DB][M]: hello");
        EFI_DEVICE_PATH_PROTOCOL *Path = LIP->FilePath;
        CDBLog("[DB][M]: PathType: %d SubType: %d", Path->Type, Path->SubType);
        panic("[DB]: I need this so I can see my results");
    }
    return 0;
}
