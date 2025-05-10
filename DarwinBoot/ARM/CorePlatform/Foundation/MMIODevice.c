// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "CoreDarwinBoot/CoreDarwinBoot.h"
#include <Drivers/Driver.h>
#include <CorePlatform/Foundation.h>
#include <Machine/MMIOAccess.h>

static UInt32 MMIODeviceReadReg32(PlatformDevice *PlatformDev, UInt32 Offset) {
    MMIODevice *dev = TO_MMIO_DEVICE(PlatformDev);

    if (dev->MemSize < Offset) {
        /* I will NOT stand for such violations in a pre-boot context. */
        panic("MMIODevice: Attempt at violating memory range for device!");
        return 0;
    } else {
        return MMIORead32(dev->BaseAddress, Offset);
    }
}

static UInt16 MMIODeviceReadReg16(PlatformDevice *PlatformDev, UInt32 Offset) {
    MMIODevice *dev = TO_MMIO_DEVICE(PlatformDev);

    if (dev->MemSize < Offset) {
        /* I will NOT stand for such violations in a pre-boot context. */
        panic("MMIODevice: Attempt at violating memory range for device!");
        return 0;
    } else {
        return MMIORead16(dev->BaseAddress, Offset);
    }
}

static UInt8 MMIODeviceReadReg8(PlatformDevice *PlatformDev, UInt32 Offset) {
    MMIODevice *dev = TO_MMIO_DEVICE(PlatformDev);

    if (dev->MemSize < Offset) {
        /* I will NOT stand for such violations in a pre-boot context. */
        panic("MMIODevice: Attempt at violating memory range for device!");
        return 0;
    } else {
        return MMIORead8(dev->BaseAddress, Offset);
    }
}

static void MMIODeviceWriteReg32(PlatformDevice *PlatformDev, UInt32 Offset, UInt32 Value) {
    MMIODevice *dev = TO_MMIO_DEVICE(PlatformDev);

    if (dev->MemSize < Offset) {
        /* I will NOT stand for such violations in a pre-boot context. */
        panic("MMIODevice: Attempt at violating memory range for device!");
    } else {
        MMIOWrite32(dev->BaseAddress, Offset, Value);
    }
}

static void MMIODeviceWriteReg16(PlatformDevice *PlatformDev, UInt32 Offset, UInt16 Value) {
    MMIODevice *dev = TO_MMIO_DEVICE(PlatformDev);

    if (dev->MemSize < Offset) {
        /* I will NOT stand for such violations in a pre-boot context. */
        panic("MMIODevice: Attempt at violating memory range for device!");
    } else {
        MMIOWrite16(dev->BaseAddress, Offset, Value);
    }
}

static void MMIODeviceWriteReg8(PlatformDevice *PlatformDev, UInt32 Offset, UInt8 Value) {
    MMIODevice *dev = TO_MMIO_DEVICE(PlatformDev);

    if (dev->MemSize < Offset) {
        /* I will NOT stand for such violations in a pre-boot context. */
        panic("MMIODevice: Attempt at violating memory range for device!");
    } else {
        MMIOWrite8(dev->BaseAddress, Offset, Value);
    }
}

bool InitMMIODevice(MMIODevice *Device, UInt64 Address, UInt32 MemSize, const char *Compatible) {
    if (Device == NULL || Address == 0 || MemSize == 0) {
        return false;
    }

    Device->BaseAddress = (volatile UInt8 *)Address;
    Device->MemSize     = MemSize;

    /* Populate callbacks. */
    Device->ReadReg32  = MMIODeviceReadReg32;
    Device->ReadReg16  = MMIODeviceReadReg16;
    Device->ReadReg8   = MMIODeviceReadReg8;
    Device->WriteReg32 = MMIODeviceWriteReg32;
    Device->WriteReg16 = MMIODeviceWriteReg16;
    Device->WriteReg8  = MMIODeviceWriteReg8;

    return InitPlatformDevice(TO_PLATFORM_DEVICE(Device), Compatible);;
}
