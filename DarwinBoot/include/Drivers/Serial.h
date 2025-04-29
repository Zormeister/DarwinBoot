// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.h>

struct {
    PlatformDriver BaseDrv;

    void (*SendString)(const char *str);
    UInt32 (*GetBaudRate)(void);
    void (*SetBaudRate)(UInt32 rate);
} typedef SerialDriver;

