// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <CorePlatform/Foundation.h>

#define EARLY_BOOT_LOG 1

#if BCM2712
    #include <Platform/SoC/BCM2712/MemoryMap.h>
#elif BCM2711
    #include <Platform/SoC/BCM2711/MemoryMap.h>
#else
    #include <Platform/SoC/BCM2712/MemoryMap.h>
#endif

#if EARLY_BOOT_LOG
    #include <Drivers/Platform/BCM2835AuxController.h>
    #include <Drivers/Serial/BCM2835AuxUART.h>
#endif

void *gProvidedDT;

/* will fix later */
MemoryRange MemRanges[] = {
    { SDRAM_BASE + 0x180000,
        SDRAM_BASE_SIZE,
        PhysicalRange,
        "SDRAM" },
};

extern void halt() __attribute__((noreturn));

extern PlatformDeviceDescriptor platform_devices[];

#if EARLY_BOOT_LOG
MMIODevice AUX;
MMIODevice UART1;

BCM2835AuxController AuxController;
BCM2835AuxUART SerialUART;
#endif

void platform_init()
{
#if EARLY_BOOT_LOG
    /* Here we are, C land. Now, let's setup our early serial driver. */

    /* First, establish our UART1 device. */
    InitMMIODevice(&AUX, platform_devices[0].Range.RangeStart, platform_devices[0].Range.RangeSize, "aux-controller,bcm2835");
    InitMMIODevice(&UART1, platform_devices[1].Range.RangeStart, platform_devices[1].Range.RangeSize, "aux-uart,bcm2835");

    BCM2835AuxControllerInit(TO_PLATFORM_DRIVER(&AuxController), TO_PLATFORM_DEVICE(&AUX));

#endif

    if (CPInitialize(MemRanges[0], platform_devices)) {

    } else {
        /* No UART yet. Can't scream for help. */
        halt();
    }
}
