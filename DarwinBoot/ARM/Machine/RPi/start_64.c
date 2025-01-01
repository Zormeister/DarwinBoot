// Copyright © 2024 Zormeister.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

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