// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_ACPI_TABLES_RSDP_H__
#define __PLATFORM_ACPI_TABLES_RSDP_H__

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

#endif /* __PLATFORM_ACPI_TABLES_RSDP_H__ */
