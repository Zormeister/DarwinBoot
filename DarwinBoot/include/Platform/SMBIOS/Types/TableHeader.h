// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_SMBIOS_TYPES_TABLEHEADER_H__
#define __PLATFORM_SMBIOS_TYPES_TABLEHEADER_H__

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

#endif /* __PLATFORM_SMBIOS_TYPES_TABLEHEADER_H__ */
