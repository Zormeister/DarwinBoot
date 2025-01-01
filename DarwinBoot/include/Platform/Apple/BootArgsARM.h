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
#include <CoreDarwinBoot/CDBBasicTypes.h>

/* man wtf why */
#define XNU_COMMANDLINE_SIZE 256

#define DISPLAYPARAMS_DEPTH_SHIFT (0)
#define DISPLAYPARAMS_ROTATION_SHIFT (8)
#define DISPLAYPARAMS_SCALE_SHIFT (16)
#define DISPLAYPARAMS_BOOTROTATE_SHIFT (24)

/* UNSIGNED LONG... */
struct {
    unsigned long BaseAddress;
    unsigned long DiplayCode;
    unsigned long RowBytes;
    unsigned long Width;
    unsigned long Height;
    unsigned long DisplayParams; /* pixel depth + rotation + scale + boot rotation? */
} typedef XNUVideoArgs;

#define BOOT_FLAG_DARKBOOT (1 << 0)

struct {
    UInt16 Revision;
    UInt16 Version;
    UInt32 VirtualBase; /* Kernel address - Virtual */
    UInt32 PhysicalBase; /* Kernel address - Physical */
    UInt32 MemorySize; /* I don't actually know what this referse to, maximum Virtual mem space? */
    UInt32 TopOfKernelData; /* "Highest physical address used in kernel data area", This essentially just means 'where does our __DATA segment end?' */
    XNUVideoArgs VideoArgs;
    UInt32 MachineType; /* ??? */
    void *DeviceTreePtr; /* i assume this helps with native addressing, in the event that the DT is outside of a 32-bit address */
    UInt32 DeviceTreeSize;
    char CommandLine[XNU_COMMANDLINE_SIZE];
    UInt32 BootFlags;
    UInt32 RealMemorySize; /* Physical RAM size, I think. */
} typedef XNUBootArguments;
