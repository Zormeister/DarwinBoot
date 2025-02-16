// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFITypes.h>

/* TODO: this. */
EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable) {
    if (CDBInitializeUEFI(SystemTable)) {
        SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
        SystemTable->ConOut->OutputString(SystemTable->ConOut, WSTRING("[DB:JS][M]: hello\n"));
    }
    return 0;
}
