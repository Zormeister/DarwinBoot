// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/SMBIOS/Types/EntryPoint.h>
#include <Platform/SMBIOS/Types/TableHeader.h>

typedef enum : UInt8 {
    kSMBIOSChassisLockBit = (1 << 7),

    kSMBIOSChassisTypeOther = 0x1,
    kSMBIOSChassisTypeUnknown = 0x2,
    kSMBIOSChassisTypeDesktop = 0x3,
    kSMBIOSChassisTypeLowProfileDesktop = 0x4,
    kSMBIOSChassisTypePizzaBox = 0x5, // pizza time
    kSMBIOSChassisTypeMiniTower = 0x6,
    kSMBIOSChassisTypeTower = 0x7,
    kSMBIOSChassisTypePortable = 0x8,
    kSMBIOSChassisTypeLaptop = 0x9,
    kSMBIOSChassisTypeNotebook = 0xA,
    kSMBIOSChassisTypeHandHeld = 0xB,
    kSMBIOSChassisTypeDockingStation = 0xC,
    kSMBIOSChassisTypeAllInOne = 0xD,
    kSMBIOSChassisTypeSubNotebook = 0xE,
    kSMBIOSChassisTypeSpaceSaving = 0xF,
    kSMBIOSChassisTypeLunchBox = 0x10,
    kSMBIOSChassisTypeMainServerChassis = 0x11,
    kSMBIOSChassisTypeExpansionChassis = 0x12,
    kSMBIOSChassisTypeSubChassis = 0x13,
    kSMBIOSChassisTypeBusExpansionChassis = 0x14,
    kSMBIOSChassisTypePeripheralChassis = 0x15,
    kSMBIOSChassisTypeRAIDChassis = 0x16,
    kSMBIOSChassisTypeRackMountChassis = 0x17,
    kSMBIOSChassisTypeSealedCasePC = 0x18,
    kSMBIOSChassisTypeMuliSystemChassis = 0x19,
    kSMBIOSChassisTypeCompactPCI = 0x1A,
    kSMBIOSChassisTypeAdvancedTCA = 0x1B,
    kSMBIOSChassisTypeBlade = 0x1C,
    kSMBIOSChassisTypeBladeEnclosure = 0x1D,
    kSMBIOSChassisTypeTablet = 0x1E,
    kSMBIOSChassisTypeConvertible = 0x1F,
    kSMBIOSChassisTypeDetachable = 0x20,
    kSMBIOSChassisTypeIoTGateway = 0x21,
    kSMBIOSChassisTypeEmbeddedPC = 0x22,
    kSMBIOSChassisTypeMiniPC = 0x23,
    kSMBIOSChassisTypeStickPC = 0x24,
} SMBIOSChassisType;

typedef enum : UInt8 {
    kSMBIOSChassisStateOther = 0x1,
    kSMBIOSChassisStateUnknown = 0x2,
    kSMBIOSChassisStateSafe = 0x3,
    kSMBIOSChassisStateWarning = 0x4,
    kSMBIOSChassisStateCritical = 0x5,
    kSMBIOSChassisStateNonRecoverable = 0x6,
} SMBIOSChassisState;

typedef enum : UInt8 {
    kSMBIOSChassisSecurityStatusOther = 0x1,
    kSMBIOSChassisSecurityStatusUnknown = 0x2,
    kSMBIOSChassisSecurityStatusNone = 0x3,
    kSMBIOSChassisSecurityStatusExternalInterfaceLockedOut = 0x4,
    kSMBIOSChassisSecurityStatusExternalInterfaceEnabled = 0x5,
} SMBIOSChassisSecurityStatus;

enum {
    kSMBIOSChassisContainedElementTypeBit = (1 << 7),
};

typedef struct {
    UInt8 Type;
    UInt8 ElementMin;
    UInt8 ElementMax;
} SMBIOSChassisContainedElement;

typedef struct {
    SMBIOSTableHeader Header;
    SMBIOSString ManufacturerName;
    SMBIOSChassisType Type;
    SMBIOSString Version;
    SMBIOSString SerialNumber;
    SMBIOSString AssetTagNumber;
    SMBIOSChassisState BootUpState;
    SMBIOSChassisState PowerSupplyState;
    SMBIOSChassisState ThermalState;
    SMBIOSChassisSecurityStatus SecurityStatus;
    UInt32 VendorField;
    UInt8 Height;
    UInt8 NumberOfPowerCords;
    UInt8 ContainedElementCount;
    UInt8 ContainedElementSize;
    SMBIOSChassisContainedElement ContainedElements[] __counted_by(ContainedElementCount);
    // SMBIOSString SKUNumber;
} SMBIOSChassisInfo;
