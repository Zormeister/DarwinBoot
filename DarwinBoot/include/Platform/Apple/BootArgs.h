// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_APPLE_BOOTARGS_H__
#define __PLATFORM_APPLE_BOOTARGS_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

#if TARGET_CPU_ARM || TARGET_CPU_ARM64
    #include <Platform/Apple/arm/BootArgs.h>
#elif TARGET_CPU_I386 || TARGET_CPU_X86_64
    #include <Platform/Apple/i386/BootArgs.h>
#else
    #error "Unsupported architecture!"
#endif

/* apparently you can also load Dexts this way, interesting. */
struct {
    UInt32 InfoPlistAddr;
    UInt32 InfoPlistSize;
    UInt32 ExecAddress;
    UInt32 ExecSize;
    UInt32 BundlePathAddr;
    UInt32 BundlePathLength;
} typedef BootKernelExtensionEntry;

// The 32-bit address limitation seems annoying though.

#endif /* __PLATFORM_APPLE_BOOTARGS_H__ */
