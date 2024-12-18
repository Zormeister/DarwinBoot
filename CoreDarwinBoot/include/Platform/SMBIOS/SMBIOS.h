// Copyright © 2024 Zormeister.

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
    FirmwareInfo = 0,
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

struct {
    SMBIOSTableHeader header;
    UInt8 FirmwareVersion; /* string */
    UInt16 BIOSLocation; /* always zero for UEFI */
    UInt8 FirmwareReleaseDate; /* string */
    UInt8 FirmwareROMSize;  /* size = fwInfoTbl->FirmwareROMSize * 64KiB, 0xFF == 16MiB or larger */
    UInt64 FirmwareFeatures; /* 'characteristics' */
    UInt8 FirmwareFeaturesExt; /* extension bytes, vers 2.1+ */
    UInt8 FirmwareFeaturesExt2; /* extension byte 2, vers 2.3+ */
    UInt8 PlatformFirmwareVersMajor; /* 2.4+  from here */
    UInt8 PlatformFirmwareVersMinor;
    UInt8 ECFirmwareVersMajor;
    UInt8 ECFirmwareVersMinor;
    UInt16 ExtendedROMSize; /* bits 0 - 13 are the size, bits 14 and 15 are unit indicators, 3.1+ */
} typedef SMBIOSFirmwareInfoTable;

#define EXTENDEDROMSIZE_UNIT_SHIFT (14)
#define EXTENDEDROMSIZE_SIZE_MASK BITMASK(0, 13)

enum {
    /* bits 0 to 2 are unk/rsvd */
    FirmwareFeaturesUnsupported = (1 << 3),
    FirmwareFeaturesHasISA = (1 << 4),
    FirmwareFeaturesHasMCA = (1 << 5),
    FirmwareFeaturesHasEISA = (1 << 6),
    FirmwareFeaturesHasPCI = (1 << 7),
    FirmwareFeaturesHasPCMCIA = (1 << 8),
    FirmwareFeaturesHasPNP = (1 << 9),
    FirmwareFeaturesHasAPM = (1 << 10),
    FirmwareFeaturesHasUpgradableFwFlash = (1 << 11),
    FirmwareFeaturesFwShadowingAllowed = (1 << 12),
    FirmwareFeaturesHasVLVESA = (1 << 13),
    FirmwareFeaturesHasESCD = (1 << 14),
    FirmwareFeaturesHasCDBoot = (1 << 15),
    FirmwareFeaturesHasSelectableBoot = (1 << 16),
    FirmwareFeaturesHasSocketedROM = (1 << 17),
    FirmwareFeaturesCanBootFromPCMCIA = (1 << 18),
    FirmwareFeaturesHasEDDSpec = (1 << 19),
    FirmwareFeaturesHasNEC9800Support = (1 << 20),
    FirmwareFeaturesHasToshiba1point2MbSupport = (1 << 21),
};

extern const char *CDBSMBIOSGetString(SMBIOSTableHeader *header, UInt32 stringIdx);

#endif
