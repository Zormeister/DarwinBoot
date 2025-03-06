// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CorePlatform/Driver.h>

struct {
    PlatformDriver BaseDrv;

    void (*sendString)(const char *str);
    UInt32 (*getBaudRate)(void);
    void (*setBaudRate)(UInt32 rate);
} typedef SerialDriver;

struct {
    PlatformDevice Dev;

    UInt32 BaudRate;
    UInt32 Bits;
    UInt32 Parity;
    UInt32 StopBitCnt;
} typedef SerialDevice;
