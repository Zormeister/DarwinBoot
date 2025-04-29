// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/ACPI/Tables/Header.h>

#define ACPI_RSDP_SIGNATURE "RSD PTR "

struct {
    char Signature[8];
    UInt8 Checksum;
    char OEMID[6];
    UInt8 Revision;
    UInt32 RSDTAddress;
} typedef ACPI_RSDP_TABLE;

struct {
    char Signature[8];
    UInt8 Checksum;
    char OEMID[6];
    UInt8 Revision;
    UInt32 RSDTAddress;
    UInt32 Length;
    UInt64 XSDTAddress;
    UInt8 ExtendedChecksum;
    UInt8 Reserved[3];
} typedef ACPI_XSDP_TABLE;
