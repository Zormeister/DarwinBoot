// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.h>

enum {
    kInterruptKindSPI = 1, /* ARM Shared PI irq. */
    kInterruptKindPPI = 2, /* ARM Private PI irq */
    kInterruptKindSGI = 3,
} typedef InterruptKind;

enum {
    kInterruptFlagsEdgeIRQ = (1 << 0),
};

struct {
    PlatformDriver BaseDrv;

    void (*EnableInterrupt)(PlatformDriver *Drv, int Interrupt);

} typedef InterruptControllerDriver;

/* !!! TODO !!! */
bool CPRegisterCPUInterruptController(InterruptControllerDriver *Driver);
