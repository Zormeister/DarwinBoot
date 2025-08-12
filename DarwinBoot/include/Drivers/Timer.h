// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.h>

struct {
    PlatformDriver BaseDrv;

    uint64_t (*GetTimerValue)(PlatformDriver *Drv);

} typedef TimerDriver;

