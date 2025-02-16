// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFITypes.h>

EFI_SYSTEM_TABLE *gST = NULL;
EFI_BOOT_SERVICES *gBS = NULL;
EFI_RUNTIME_SERVICES *gRT = NULL;

/* uhhhhhh */
#define CL(a) \
  u ## a

/* implementing a vsnprintf-like thing is going to kill me */

bool CDBInitializeUEFI(EFI_SYSTEM_TABLE *SystemTable) {
    /* we can't exactly scream for help right now, */
    if (SystemTable->Header.Signature != EFI_SYSTEM_TABLE_SIGNATURE) {
        return false;
    }
    if (SystemTable->BootServices == NULL || SystemTable->RuntimeServices == NULL || SystemTable->ConOut == NULL) {
        return false;
    }
    SystemTable->ConOut->Reset(SystemTable->ConOut, false);
    SystemTable->ConOut->OutputString(SystemTable->ConOut, CL("[CDB][UEFI]: Initialize has reached console out.\n"));
    return true;
}
