// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <CorePlatform/Foundation.h>

/* so VSCode/IntelliSense shuts up. */
#ifdef INTELLISENSE
#define BCM2712 1
#endif

#if BCM2712
#include <Platform/SoC/BCM2712/MemoryMap.h>
#elif BCM2711
#include <Platform/SoC/BCM2711/MemoryMap.h>
#endif

void *gProvidedDT;

/* will fix later */
MemoryRange MemRanges[] = {
    {
        SDRAM_BASE + 0x180000,
        SDRAM_BASE_SIZE,
    },
};

extern void halt() __attribute__((noreturn));

extern PlatformDeviceDescriptor platform_devices[];

void platform_init() {
    /* Here we are, C land. Now, let's setup our early serial driver. */

    if (CPInitialize(MemRanges[0], platform_devices)) {
        
    } else {
        /* No UART yet. Can't scream for help. */
        halt();
    }
}