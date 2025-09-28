// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_ARM_BOOTARGS_H__
#define __PLATFORM_APPLE_ARM_BOOTARGS_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

/* man wtf why */
#define XNU_COMMANDLINE_SIZE 256

#define DISPLAYPARAMS_DEPTH_SHIFT      (0)
#define DISPLAYPARAMS_ROTATION_SHIFT   (8)
#define DISPLAYPARAMS_SCALE_SHIFT      (16)
#define DISPLAYPARAMS_BOOTROTATE_SHIFT (24)

/* UNSIGNED LONG... */
struct {
    unsigned long BaseAddress;
    unsigned long DisplayCode;
    unsigned long RowBytes;
    unsigned long Width;
    unsigned long Height;
    unsigned long DisplayParams; /* pixel depth + rotation + scale + boot rotation? */
} typedef XNUVideoArgs;

#define BOOT_FLAG_DARKBOOT (1 << 0) // What is 'darkboot?'

struct {
    UInt16 Revision;
    UInt16 Version;
    UInt32 VirtualBase;     /* Kernel address - Virtual */
    UInt32 PhysicalBase;    /* Kernel address - Physical */
    UInt32 MemorySize;      /* I don't actually know what this referse to, maximum Virtual mem space? */
    UInt32 TopOfKernelData; /* "Highest physical address used in kernel data area", This essentially just means 'where does our __DATA segment end?' */
    XNUVideoArgs VideoArgs;
    UInt32 MachineType;  /* ??? */
    void *DeviceTreePtr; /* i assume this helps with native addressing, in the event that the DT is outside of a 32-bit address */
    UInt32 DeviceTreeSize;
    char CommandLine[XNU_COMMANDLINE_SIZE];
    UInt32 BootFlags;
    UInt32 RealMemorySize; /* Physical RAM size, I think. */
} typedef XNUBootArguments;

#endif /* __PLATFORM_APPLE_ARM_BOOTARGS_H__ */
