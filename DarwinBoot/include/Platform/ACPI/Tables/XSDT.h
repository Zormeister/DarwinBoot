// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_XSDT_H__
#define __PLATFORM_ACPI_TABLES_XSDT_H__

#include <Platform/ACPI/Tables/Header.h>

#define ACPI_XSDT_SIGNATURE "XSDT"

struct {
    ACPI_TABLE_HEADER header;
    UInt64 Tables[];
} typedef ACPI_XSDT_TABLE;

#endif
