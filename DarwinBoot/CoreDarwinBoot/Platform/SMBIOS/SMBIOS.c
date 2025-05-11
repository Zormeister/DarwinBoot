// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>
#include <Platform/SMBIOS/SMBIOS.h>

EFI_GUID gSmbiosTableGuid = SMBIOS_TABLE_GUID;
EFI_GUID gEfiSmbiosV3TableGuid = SMBIOS3_TABLE_GUID;

const char *CDBSMBIOSGetString(SMBIOSTableHeader *header, UInt32 stringIdx) {
    UInt8 *Raw = (UInt8 *)header;
    UInt32 size = header->Length;
    return NULL;
}
