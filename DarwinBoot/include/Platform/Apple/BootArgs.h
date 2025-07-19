// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#if __arm64__ || __arm__
    #include <Platform/Apple/BootArgsARM.h>
#endif

// How do I disable clang warnings about unused headers?
#if __x86_64__ || __i386__
    #include <Platform/Apple/BootArgsX86.h>
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
