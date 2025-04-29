// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Drivers/Platform/BCM2835AuxController.h>

struct BCM2835AuxControllerPrivateData {
    MMIODevice *AuxDev;

    bool UARTState;
    bool SPI1State;
    bool SPI2State;
};



