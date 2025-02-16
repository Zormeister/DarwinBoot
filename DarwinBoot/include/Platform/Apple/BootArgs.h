// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#if TARGET_ARM32 || TARGET_ARM64
#include "BootArgsARM.h"
#endif

// How do I disable clang warnings about unused headers?
#if TARGET_X64 || TARGET_IA32
#include "BootArgsX86.h"
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