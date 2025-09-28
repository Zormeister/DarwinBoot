// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_BGRT_H__
#define __PLATFORM_ACPI_TABLES_BGRT_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/ACPI/Tables/Header.h>

#define ACPI_BGRT_SIGNATURE "BGRT"

struct {
    ACPI_TABLE_HEADER header;
    UInt32 Version;
    UInt8 Status;
    UInt8 ImageType;
    UInt64 ImageAddress;
    UInt32 ImageX;
    UInt32 ImageY;
} typedef ACPI_BGRT_TABLE;

#endif /* __PLATFORM_ACPI_TABLES_BGRT_H__ */
