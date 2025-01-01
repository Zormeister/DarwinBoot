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