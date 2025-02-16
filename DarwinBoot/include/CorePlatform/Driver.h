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

struct {
    const char *DriverName;
    void *Device;
    DriverClass Class;
    DriverSubClass SubClass;
} typedef PlatformDriver;

struct {
    const char *Compatible;

    bool (*conformsTo)(const char *Compatible);
} typedef PlatformDevice;

struct CorePlatformDriverInfo {
    const char *DrvName;
    bool (*IsSupported)(PlatformDevice *dev);
    PlatformDriver * (*CreateDriver)(PlatformDevice *dev);
    void (*DestroyDriver)(PlatformDriver *This);
};