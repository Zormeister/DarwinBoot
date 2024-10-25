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

#if PLATFORM_SMBIOS == 1

#define SMBIOS_TABLE_GUID \
  {0xeb9d2d31,0x2d88,0x11d3,\
   {0x9a,0x16,0x00,0x90,0x27,0x3f,0xc1,0x4d}}

#define SMBIOS3_TABLE_GUID \
  {0xf2fd1544, 0x9794, 0x4a2c,\
    {0x99,0x2e,0xe5,0xbb,0xcf,0x20,0xe3,0x94}}

/* LAST SYNC: SMBIOS 3.8.0 */
      
#define SMBIOS_ANCHOR_64 "_SM3_"
#define SMBIOS_ANCHOR_32 "_SM_"

struct SMBIOS_ENTRY_POINT_32 {
    char anchor[4];
    UInt8 checksum;
    UInt8 entryLength;
    UInt8 versionMajor;
    UInt8 versionMinor;
    UInt16 structMaxSize;
    UInt8 entryRev;
    UInt8 formatted[5];
    UInt8 intermAnchor[5];
    UInt8 intermChecksum;
    UInt16 structTableLength;
    UInt32 structTableAddr;
    UInt8 bcdRev;
};

enum SMBIOS_ENTRY_REVISION {
    Reserved0 = 0,
    SMBIOS3 = 1,
};

struct SMBIOS_ENTRY_POINT_64 {
    char anchor[5]; 
    UInt8 checksum;
    UInt8 entryLength;
    UInt8 versionMajor;
    UInt8 versionMinor;
    UInt8 docRev;
    UInt8 entryRev;
    UInt8 rsvd;
    UInt32 size;
    UInt64 address;
};

struct {
    UInt8 Type;
    UInt8 Length;
    UInt16 Handle;
} typedef SMBIOSTableHeader;

enum {
    BIOSInfo = 0,
    SystemInfo,
    MainboardInfo,
    ChasisInfo,
    ProcessorInfo,
    CacheInfo = 7,
    SystemSlotInfo = 9,
    PhysicalMemArray = 16,
    MemoryDeviceInfo,
    MemoryMappedAddresses = 19, /* 'Memory Array Mapped Address' */
} typedef SMBIOSTableType;

#endif
