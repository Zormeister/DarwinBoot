// Copyright © 2024 Zormeister. All rights reserved.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#if PLATFORM_ACPI

#define EFI_ACPI_20_TABLE_GUID \
  {0x8868e871,0xe4f1,0x11d3,\
    {0xbc,0x22,0x00,0x80,0xc7,0x3c,0x88,0x81}}

#define ACPI_TABLE_GUID \
  {0xeb9d2d30,0x2d88,0x11d3,\
    {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

#define ACPI_RSDP_SIGNATURE "RSD PTR "

#define ACPI_MADT_SIGNATURE "APIC"
#define ACPI_BGRT_SIGNATURE "BGRT"
#define ACPI_FADT_SIGNATURE "FACP"
#define ACPI_RSDT_SIGNATURE "RSDT"
#define ACPI_XSDT_SIGNATURE "XSDT"

struct ACPIRootSystemDescPtrTable {
    char Signature[8];
    
};

struct ACPITableHeader {
    char Signature[4];
    UInt32 Length;
    UInt8 Revision;
    UInt8 Checksum;
    char OEMID[6];
    char OEMTableID[8];
    UInt32 OEMRevision;
    UInt32 CreatorID;
    UInt32 CreatorRevision;
};

typedef struct ACPITableHeader ACPITableHeader;

struct ACPIRSDTTable {
    ACPITableHeader header;
    UInt32 Entries[];
};

struct ACPIXSDTTable {
    ACPITableHeader header;
    UInt64 Entries[];
};

struct ACPIBGRTTable {
    ACPITableHeader header;
    UInt32 Version;
    UInt8 Status;
    UInt8 ImageType;
    UInt64 ImageAddress;
    UInt32 ImageX;
    UInt32 ImageY;
};

struct {
    UInt64 BaseAddress;
    UInt16 SegmentGroupNum;
    UInt8 StartBusNumber;
    UInt8 EndBusNumber;
    UInt32 Reserved;
} typedef ACPIMCFGEntry;

struct {
    ACPITableHeader header;
    UInt64 Reserved;
    ACPIMCFGEntry Entries[]; /*  (header.size -= sizeof(ACPITableHeader) + 8) / sizeof(ACPIMCFGEntry) */
} typedef ACPIMCFGTable;

#endif
