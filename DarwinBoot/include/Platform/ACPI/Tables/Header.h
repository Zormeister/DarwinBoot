// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_HEADER_H__
#define __PLATFORM_ACPI_TABLES_HEADER_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    char Signature[4];
    UInt32 Length;
    UInt8 Revision;
    UInt8 Checksum;
    char OEMID[6];
    char OEMTableID[8];
    UInt32 OEMRevision;
    UInt32 CreatorID;
    UInt32 CreatorRevision;
} typedef ACPI_TABLE_HEADER;

#endif /* __PLATFORM_ACPI_TABLES_HEADER_H__ */
