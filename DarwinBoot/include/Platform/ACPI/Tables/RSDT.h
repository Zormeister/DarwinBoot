// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/ACPI/Tables/Header.h>

#define ACPI_RSDT_SIGNATURE "RSDT"

struct {
    ACPITableHeader Header;
    UInt32 Tables[];
} typedef ACPI_RSDT_TABLE;
