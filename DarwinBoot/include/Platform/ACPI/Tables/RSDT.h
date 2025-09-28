// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_RSDT_H__
#define __PLATFORM_ACPI_TABLES_RSDT_H__

#include <Platform/ACPI/Tables/Header.h>

#define ACPI_RSDT_SIGNATURE "RSDT"

struct {
    ACPI_TABLE_HEADER Header;
    UInt32 Tables[];
} typedef ACPI_RSDT_TABLE;

#endif /* __PLATFORM_ACPI_TABLES_RSDT_H__ */
