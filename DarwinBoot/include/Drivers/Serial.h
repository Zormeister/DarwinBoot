// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.h>

struct {
    PlatformDriver BaseDrv;

    UInt32 (*GetBaudRate)(PlatformDriver *drv);
    void (*SetBaudRate)(PlatformDriver *drv, UInt32 rate);

    /* Callbacks for platform_vprintf */
    void (*PutC)(PlatformDriver *drv, char c);
    char (*GetC)(PlatformDriver *drv);
} typedef SerialDriver;
