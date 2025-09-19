// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/MMIODevice.hpp>

using namespace CorePlatform;

#if DEBUG || DEVELOPMENT || MMIODEVICE_ALLOW_DBG
#define PRINT(printf...) printf(##printf)
#else
#define PRINT(printf...)
#endif

CMMIODevice::CMMIODevice(const char **ppCompatibleID, size_t numCompatibles, physical_address_t addr, size_t memSize) : CDevice(ppCompatibleID, numCompatibles)
{
    PRINT("MMIO device created -- 0x%llX (space: 0x%llX)", addr, memSize);
    fAddress = addr;
    fRegisters = (volatile UInt8 *)addr;
}