// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

enum {
    UART = 1,
} typedef DriverSubClass;

enum {
    Abstract = 0,
    Serial = 1,
    Video = 2,
} typedef DriverClass;
/* ^ TODO: clean this shit out */

struct {
    const char **Compatible;
    size_t NumCompatibles;

    bool (*ConformsTo)(const char *Compatible);
} typedef PlatformDevice;

typedef struct _PlatformDriver PlatformDriver;

struct _PlatformDriver {
    const char *DriverName;
    DriverClass Class;
    DriverSubClass SubClass;

    /* Base routines */
    bool (*Init)(PlatformDriver *This, PlatformDevice *Device);
    bool (*Shutdown)(PlatformDriver *This);
};

#define TO_PLATFORM_DRIVER(dev) (PlatformDriver *)(dev)

bool InitPlatformDevice(PlatformDevice *Dev, const char *Compatible);

#define TO_PLATFORM_DEVICE(dev) (PlatformDevice *)(dev)

struct {
    PlatformDevice Base;

    volatile UInt8 *BaseAddress;
    UInt32 MemSize;

    /* callbacks */
    UInt8 (*ReadReg8)(PlatformDevice *This, UInt32 Offset);
    UInt16 (*ReadReg16)(PlatformDevice *This, UInt32 Offset);
    UInt32 (*ReadReg32)(PlatformDevice *This, UInt32 Offset);

    void (*WriteReg8)(PlatformDevice *This, UInt32 Offset, UInt8 Value);
    void (*WriteReg16)(PlatformDevice *This, UInt32 Offset, UInt16 Value);
    void (*WriteReg32)(PlatformDevice *This, UInt32 Offset, UInt32 Value);
} typedef MMIODevice;

#define TO_MMIO_DEVICE(dev) (MMIODevice *)(dev)

bool InitMMIODevice(MMIODevice *Device, UInt64 Address, UInt32 MemSize, const char *Compatible);
