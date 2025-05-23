// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CorePlatform/Foundation.h>

/* MemoryManager!!! */

/* Enables large memory seegments.  */
#define MEMMAN_LARGE_REGIONS 1

#if MEMMAN_LARGE_REGIONS
#define kKernelRegionSize 0x02000000 /* 32M */
#define kBootMemRegionSize 0x08000000 /* 128M */
#else
#define kKernelRegionSize 0x01000000 /* 16M */
#define kBootMemRegionSize 0x04000000 /* 64M */
#endif

enum {
    kCPMemoryRegionBootMem = 1,
    kCPMemoryRegionKernelMem,
} typedef CPMemoryRegion;

/* Interfaces for the Machine folders to interact with */

/* Initialize the Memory Manager given the provided ranges */
bool CPMemoryManagerInit(MemoryRange *Ranges, size_t NumRanges);

/* Disallow any modification to the memory range specified. */
bool CPMemoryManagerBlacklistRange(MemoryRange *RsvdRange);

/* Memory services!!! */
void *CPMemoryManagerAllocate(CPMemoryRegion Region, size_t Size);
