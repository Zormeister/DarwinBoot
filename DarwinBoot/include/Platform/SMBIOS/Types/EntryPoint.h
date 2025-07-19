// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#define SMBIOS_ANCHOR_64 "_SM3_"
#define SMBIOS_ANCHOR_32 "_SM_"

typedef UInt8 SMBIOSString;

typedef struct {
    char Anchor[4];
    UInt8 Checksum;
    UInt8 EntryLength;
    UInt8 VersionMajor;
    UInt8 VersionMinor;
    UInt16 StructMaxSize;
    UInt8 EntryRev;
    UInt8 Formatted[5];
    UInt8 IntermAnchor[5];
    UInt8 IntermChecksum;
    UInt16 StructTableLength;
    UInt32 StructTableAddr;
    UInt8 BcdRev;
} PACKED SMBIOS_ENTRY_POINT_32;

typedef enum {
    Reserved0 = 0,
    SMBIOS3 = 1,
} SMBIOS_ENTRY_REVISION;

typedef struct {
    char Anchor[5];
    UInt8 Checksum;
    UInt8 EntryLength;
    UInt8 VersionMajor;
    UInt8 VersionMinor;
    UInt8 DocRev;
    UInt8 EntryRev;
    UInt8 Rsvd;
    UInt32 Size;
    UInt64 Address;
} PACKED SMBIOS_ENTRY_POINT_64;

typedef union {
    SMBIOS_ENTRY_POINT_32 Entry32;
    SMBIOS_ENTRY_POINT_64 Entry64;
} SMBIOSEntryPoint;
