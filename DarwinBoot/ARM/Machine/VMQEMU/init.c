// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "Machine/VMQEMU/MemoryMap.h"
#include <CorePlatform/Foundation.h>
#include <Machine/VMQEMU/VMQEMU.h>

void *VMQFlatDT;

MemoryRange MemoryRanges[3] = {
    {SDRAM_BASE + FDT_SIZE, 0x0, 0x0},
};

// This assumes we're booting as an EABI exec, rather than as an ELF64

void platform_init() {
    if (CPInitialize(MemoryRanges[0], NULL)) {
    
    }
}