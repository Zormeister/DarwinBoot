// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    UInt8 Type;
    UInt8 Length;
    UInt16 Handle;
} typedef SMBIOSTableHeader;

enum {
    FirmwareInfo = 0,
    SystemInfo,
    BaseboardInfo,
    ChasisInfo,
    ProcessorInfo,
    CacheInfo = 7,
    SystemSlotInfo = 9,
    PhysicalMemArray = 16,
    MemoryDeviceInfo,
    MemoryMappedAddresses = 19, /* 'Memory Array Mapped Address' */
} typedef SMBIOSType;
