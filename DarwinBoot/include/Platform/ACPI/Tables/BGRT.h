// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/ACPI/Tables/Header.h>

#define ACPI_BGRT_SIGNATURE "BGRT"

struct {
    ACPITableHeader header;
    UInt32 Version;
    UInt8 Status;
    UInt8 ImageType;
    UInt64 ImageAddress;
    UInt32 ImageX;
    UInt32 ImageY;
} typedef ACPI_BGRT_TABLE;
