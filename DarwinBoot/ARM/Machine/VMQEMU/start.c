// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>
#include <Machine/VMQEMU/VMQEMU.h>

void *FDT;

MemoryRange MemoryRanges[3] = {
    {0x0, 0x0, 0x0},
};

// This assumes we're booting as an EABI exec, rather than as an ELF64

void platform_init() {
    MemoryConfig cfg;
    
}