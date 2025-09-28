// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_MCFG_H__
#define __PLATFORM_ACPI_TABLES_MCFG_H__

#include <Platform/ACPI/Tables/Header.h>

#define ACPI_MCFG_SIGNATURE "MCFG"

struct {
    UInt64 BaseAddress;
    UInt16 SegmentGroupNum;
    UInt8 StartBusNumber;
    UInt8 EndBusNumber;
    UInt32 Reserved;
} typedef ACPI_MCFG_TABLE_ENTRY;

struct {
    ACPI_TABLE_HEADER header;
    UInt64 Reserved;
    ACPI_MCFG_TABLE_ENTRY Entries[]; /*  (header.size -= sizeof(ACPITableHeader) + 8) / sizeof(ACPI_MCFG_TABLE_ENTRY) */
} typedef ACPI_MCFG_TABLE;

#endif /* __PLATFORM_ACPI_TABLES_MCFG_H__ */
