// Copyright © 2024 Zormeister.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#include <CoreDarwinBoot/CoreDarwinBoot.h>

EFI_SYSTEM_TABLE *gST = NULL;
EFI_BOOT_SERVICES *gBS = NULL;
EFI_RUNTIME_SERVICES *gRT = NULL;

/* uhhhhhh */
#define CL(a) \
  L ## a

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
