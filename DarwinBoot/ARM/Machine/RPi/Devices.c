// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>
#include <Drivers/Driver.h>

#if BCM2835 || BCM2836
    #include <Platform/SoC/BCM2835/MemoryMap.h>
#elif BCM2837
    #include <Platform/SoC/BCM2837/MemoryMap.h>
#elif BCM2711 || BCM2712
    #include <Platform/SoC/BCM2711/MemoryMap.h>
    #include <Platform/SoC/BCM2711/Peripherals.h>
#else
    /* In the event we don't actually have any set SoC, default to 2711 for clangd's sake. */
    #include <Platform/SoC/BCM2711/MemoryMap.h>
    #include <Platform/SoC/BCM2711/Peripherals.h>
#endif

/* where should I even put this so that CorePl- actually I can just make a function on startup */
PlatformDeviceDescriptor platform_devices[] = {
    { "aux,bcm2835", { AUX_BASE, 0x40, MMIORange, "AUX" } },
    { "aux-uart,bcm2835", { UART1_BASE, 0x50, MMIORange, "UART1" } },
    { "uart,arm-pl011", { UART0_BASE, 0x1000, MMIORange, "UART0" } }, /* I didn't research the reg size. I'll fix this later. */
    { NULL, 0, {} },
};
