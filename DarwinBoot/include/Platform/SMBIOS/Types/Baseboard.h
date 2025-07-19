// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/SMBIOS/Types/EntryPoint.h>
#include <Platform/SMBIOS/Types/TableHeader.h>

typedef enum : UInt8 {
    kSMBIOSBaseboardBoardTypeUnknown = 0x1,
    kSMBIOSBaseboardBoardTypeOther = 0x2,
    kSMBIOSBaseboardBoardTypeServerBlade = 0x3,
    kSMBIOSBaseboardBoardTypeConnectivitySwitch = 0x4,
    
} SMBIOSBaseboardBoardType;

typedef struct {
    SMBIOSTableHeader Header;
    SMBIOSString ManufacturerName;
    SMBIOSString Product;
    SMBIOSString Version;
    SMBIOSString SerialNumber;
    SMBIOSString AssetTag;
    UInt8 FeatureFlags;
    SMBIOSString LocationInChassis;
    UInt16 ChassisHandle;
    SMBIOSBaseboardBoardType BoardType;
    UInt8 NumObjectHandles;
    UInt16 ObjectHandles[] __counted_by(NumObjectHandles);
} PACKED SMBIOSBaseboardInfo;
