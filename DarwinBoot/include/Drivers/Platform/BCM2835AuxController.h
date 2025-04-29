// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.h>

struct BCM2835AuxControllerPrivateData;

struct {
    PlatformDriver Driver;

    void (*enableUART)(bool enable);
    void (*enableSPI)(UInt8 spi, bool enable);

    struct BCM2835AuxControllerPrivateData *PrivateData;
} typedef BCM2835AuxController;

/* In-memory creation. */
BCM2835AuxController *BCM2835AuxControllerCreate(PlatformDevice *dev);

/* This will initialise any old BCM2835AuxController object, so long as you have a PlatformDevice */
bool BCM2835AuxControllerInit(BCM2835AuxController *controller, PlatformDevice *dev);
