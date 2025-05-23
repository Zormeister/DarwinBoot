// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>
#include <CorePlatform/MemoryManager.h>

/* !!! */

struct {
    size_t NumRanges;
    MemoryRange *Ranges;
} typedef MemoryManager;

static MemoryRange KernelMemoryRegion;
static MemoryRange BootMemoryRegion;

// I have a stupid idea.
struct MemoryAllocation {
    size_t size; /* Keep track of the size of the data. If this gets overridden I'm cooked. */
    uint8_t data[]; /* THE data. */
};

bool CPMemoryManagerInit(MemoryRange *Ranges, size_t NumRanges) {

}
