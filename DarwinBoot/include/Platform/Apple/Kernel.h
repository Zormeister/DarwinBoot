// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/Apple/KernelCache.h>

/*
 * This is on the prebot volume. A friend's MacBook had it at <PREBOOT>/boot/<SOME ID>/System/Library/Caches/com.apple.kernelcache/kernelcache
 * I wonder if the 'current' file in <PREBOOT>/boot is *actually* a boot nonce or something. I doubt it, but just a thought,
 */
#define EMBEDDED_KERNEL_PATH "/System/Library/Caches/com.apple.kernelcache/kernelcache"

/*
 * How does Bless place the kernelcache on the Preboot volume?
 */

#define KERNEL_COLLECTION_PATH "/System/Library/KernelCollections/BootKernelExtensions.kc"
/* I /swear/ it was called BootKernelCollection prior to macOS Sequoia */
#define KERNEL_COLLECTION_OLD_PATH "/System/Library/KernelCollections/BootKernelCollection.kc"

/* ah prelinkedkernel... rest in peace. */
#define KERNEL_PRELINKED_PATH "/System/Library/PrelinkedKernels/prelinkedkernel"

// prelinkedkernel wrapped nicely in an IMG4, I believe this is the base kernel for IMG4 validation
// I think the .<T2 AP>.im4m files just describe EfiBoot/the kernelcache? I'd have to check.
#define SECURE_PRELINKED_PATH "/System/Library/PrelinkedKernels/immutablekernel"

/* TODO: I need to live-translate these to the respective SoC kernel while booting */
/* EG: kernel.release.bcm2837 or in my case kernel.development.bcm2712 */
#define KERNEL_PATH "/System/Library/Kernels/kernel"

/* I believe these also had the .VARIANT.SoC style naming, on iOS of course. */
#define KERNEL_OLD_PATH "/mach_kernel"

enum KernelLoadType {
    kLoadTypeRawLoad, /* Find every needed boot extension and load it into the memory map */
    kLoadTypeCachedLoad, /* Use the kernel cache to load. */
};
