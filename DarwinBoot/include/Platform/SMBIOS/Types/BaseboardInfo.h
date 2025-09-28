// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_BASEBOARDINFO_H__
#define __PLATFORM_SMBIOS_TYPES_BASEBOARDINFO_H__

#include <Platform/SMBIOS/Types/EntryPoint.h>
#include <Platform/SMBIOS/Types/TableHeader.h>

typedef enum : UInt8 {
    kSMBIOSBaseboardBoardTypeUnknown = 0x1,
    kSMBIOSBaseboardBoardTypeOther = 0x2,
    kSMBIOSBaseboardBoardTypeServerBlade = 0x3,
    kSMBIOSBaseboardBoardTypeConnectivitySwitch = 0x4,
    kSMBIOSBaseboardBoardTypeSystemManagementModule = 0x5,
    kSMBIOSBaseboardBoardTypeProcessorModule = 0x6,
    kSMBIOSBaseboardBoardTypeIOModule = 0x7,
    kSMBIOSBaseboardBoardTypeMemoryModule = 0x8,
    kSMBIOSBaseboardBoardTypeDaughterBoard = 0x9,
    kSMBIOSBaseboardBoardTypeMotherboard = 0xA,
    kSMBIOSBaseboardBoardTypeProcessorAndMemoryModule = 0xB,
    kSMBIOSBaseboardBoardTypeProcessorAndIOModule = 0xC,
    kSMBIOSBaseboardBoardTypeInterconnectBoard = 0xD,
} SMBIOSBaseboardBoardType;

enum {
    kSMBIOSBaseboardFlagIsHosting = (1 << 0),
    kSMBIOSBaseboardFlagRequireDaughterBoard = (1 << 1),
    kSMBIOSBaseboardFlagIsRemoveable = (1 << 2),
    kSMBIOSBaseboardFlagIsReplaceable = (1 << 3),
    kSMBIOSBaseboardFlagIsHotSwappable = (1 << 4),
};

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

#endif /* __PLATFORM_SMBIOS_TYPES_BASEBOARDINFO_H__ */
