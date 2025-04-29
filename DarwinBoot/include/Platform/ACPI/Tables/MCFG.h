// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/ACPI/Tables/Header.h>

#define ACPI_MCFG_SIGNATURE "MCFG"

struct {
    UInt64 BaseAddress;
    UInt16 SegmentGroupNum;
    UInt8 StartBusNumber;
    UInt8 EndBusNumber;
    UInt32 Reserved;
} typedef MCFGTableEntry;

struct {
    ACPITableHeader header;
    UInt64 Reserved;
    MCFGTableEntry Entries[]; /*  (header.size -= sizeof(ACPITableHeader) + 8) / sizeof(ACPI_MCFG_TABLE_ENTRY) */
} typedef ACPI_MCFG_TABLE;

