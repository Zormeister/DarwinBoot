// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/Apple/MachO.h>
#include <Platform/Apple/BootArgs.h>

enum {
    MKext,
    Prelinked,
    Fileset,
    Pageable, // We shouldn't be loading pagable KCs, not yet in the boot chain.
    // Maybe for preloading the AuxKC in the case of ARM64 macOS?
} typedef KernelCacheKind;

enum {
    LZFSE = 'lzvn',
    LZSS = 'lzss',
} typedef KernelCacheCompression;

#define kKernelCacheSignature 'comp'
