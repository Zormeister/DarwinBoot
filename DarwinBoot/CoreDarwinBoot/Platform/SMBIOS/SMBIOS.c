// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>

const char *CDBSMBIOSGetString(SMBIOSTableHeader *header, UInt32 stringIdx) {
    UInt8 *Raw = (UInt8 *)header;
    UInt32 size = header->Length;
}
