// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "Drivers/Driver.h"
#include <Drivers/Serial.h>
#include <CorePlatform/Foundation.h>

/* Per SoC headers - usually because the SoC bases are different  */
/* I should describe the UART1 bases and other peripheral bases in Platfrom/SoC/BCM2711/Platform.c */

#if BCM2835 || BCM2836 || BCM2837
#include <Platform/SoC/BCM2835/Peripherals.h>
#elif BCM2711 || BCM2712
#include <Platform/SoC/BCM2711/Peripherals.h>
#include <Platform/SoC/BCM2711/Regs/AuxRegs.h>
#include <Platform/SoC/BCM2711/Regs/UART1Regs.h>
#endif

/* TODO: everything */

struct BCM2835AuxUARTDriver {
    SerialDriver base;

    UInt64 MMIOBase;
    UInt32 (*readReg)(UInt32 reg);
    void (*writeReg)(UInt32 reg, UInt32 value);
};

static struct BCM2835AuxUARTDriver bcm2835_aux_uart_drv;

bool bcm2835_aux_uart_is_supported(PlatformDevice *dev) {
    if (dev->ConformsTo("brcm,brcm2835-aux-uart") || dev->ConformsTo("aux-uart,bcm2835")) {
        return true;
    }
    return false;
}

PlatformDriver * bcm2835_aux_uart_create() {
    return (PlatformDriver *)&bcm2835_aux_uart_drv; /* We should only ever have one context. BCM283X + BCM27XX platform should init us. */
}

void bcm2835_aux_uart_destroy(PlatformDriver *This) {

    return;
}

// now, how 2 get runtime to scan for drivers
struct CorePlatformDriverInfo bcm2835_aux_uart_drv_info = {
    "bcm2835-aux-uart",
    bcm2835_aux_uart_is_supported,
    bcm2835_aux_uart_create,
    bcm2835_aux_uart_destroy,
};

