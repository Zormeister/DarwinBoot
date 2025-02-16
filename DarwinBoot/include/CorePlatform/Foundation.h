// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CorePlatform/Driver.h>

struct {
    const char * Compatible;
    UInt32 *RegBases;
    UInt32 *RegBaseSize;
    UInt32 NumRegBases; /*  */
} typedef PlatformDeviceDescriptor;

struct {
    UInt64 MemBase;
    UInt64 MemSize;
} typedef MemoryConfig;

struct {
    UInt64 RangeStart;
    UInt64 RangeVirtualStart;
    UInt64 RangeSize;
    const char *RangeName;
} typedef MemoryRange;

/* PHYSICAL PAGES... */
struct {
    UInt64 PageStart;
    UInt64 PageEnd;
    UInt32 AvailableSpace;
    UInt32 Rsvd;
} typedef PageMapEntry; /* 24 bytes per map entry, so... */
/* 170 entries per page. I don't think a single page would fit 4096 / 8GB of pages map entries. Oof.  */

/* .drivers should get parsed by CorePlatformInitialize at runtime. */
#define COREPLATFORM_DRIVER __attribute__((section(".drivers"))) 


bool CorePlatformInitialize(MemoryConfig memcfg, PlatformDeviceDescriptor *Devices);

void AddRangeToPageMap(MemoryConfig newcfg);