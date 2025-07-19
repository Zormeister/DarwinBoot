// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/SMBIOS/Types/EntryPoint.h>
#include <Platform/SMBIOS/Types/TableHeader.h>

enum : UInt8 {
    kSMBIOSWakeTypeOther = 0x1,
    kSMBIOSWakeTypeUnknown = 0x2,
    kSMBIOSWakeTypeAPMTimer = 0x3,
    kSMBIOSWakeTypeModemRing = 0x4,
    kSMBIOSWakeTypeLANRemote = 0x5,
    kSMBIOSWakeTypePowerSwitch = 0x6,
    kSMBIOSWakeTypePCIPME = 0x7,
    kSMBIOSWakeTypeACPowerRestored = 0x8,
} typedef SMBIOSSystemWakeType;

struct {
    SMBIOSTableHeader Header;
    SMBIOSString ManufacturerName;
    SMBIOSString SystemProductName;
    SMBIOSString SystemProductVersion;
    SMBIOSString SystemSerialNumber;
    uuid_t SystemUUID;
    SMBIOSSystemWakeType SystemWakeType;
    SMBIOSString SystemSKUNumber;
    SMBIOSString SystemFamily;
} PACKED typedef SMBIOSSystemInfoTable;

