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

/* This is a FAT variable for the 8GB boards. */
/* Dynamically allocate instead? */
PageMapEntry PageMap[MAX_PAGES];

/* will fix later */
MemoryRange MemRanges[] = {
    {
        SDRAM_BASE,
        SDRAM_BASE_SIZE,
    },
};

extern void panic_halt();

extern struct PlatformDeviceDescriptor platform_devices[];

void platform_init() {
    MemoryConfig base;
    /* Initial memory size, so we can make sure that we don't burst into flames before we use the full available RAM. */
    /* I wonder if we can use the higher regions of RAM to KASLR the XNU kernel to some random location in there. */
    base.MemBase = SDRAM_BASE;
    base.MemSize = SDRAM_BASE_SIZE;
    if (CorePlatformInitialize(base, platform_devices)) {
        
    } else {
        /* No UART yet. Can't scream for help. */
        panic_halt();
    }
}