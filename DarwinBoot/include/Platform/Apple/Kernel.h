// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/Apple/MachO.h>
#include <Platform/Apple/PrelinkedKernel.h>
#include <Platform/Apple/MKext.h>
#include <Platform/Apple/KernelCollection.h>

/*
 * This is on the Preboot volume. A friend's MacBook had it at <PREBOOT>/boot/<SOME ID>/System/Library/Caches/com.apple.kernelcache/kernelcache
 * I wonder if the 'current' file in <PREBOOT>/boot is *actually* a boot nonce or something. I doubt it, but just a thought,
 */
#define kEmbeddedKernelCachePath "/System/Library/Caches/com.apple.kernelcache/kernelcache"

/* 
 * I would just like to give a huge thanks to one of my real life friends who let me extract
 * his personalised kernelcache + DeviceTree payloads. And the IORegistry while I was at it.
 *
 * I should document additional IMG4 tags within some other file, or maybe a DarwinImage4 project
 * if I ever feel like it.
 *
 * XNU needs the Kernel-Extension-Component after all.
 */

/* TODO: I need to live-translate these to the respective SoC kernel while booting */
/* EG: kernel.bcm2837 or in my case kernel.development.bcm2712 */
#define kKernelPath "/System/Library/Kernels/kernel"

/* I believe these also had the .VARIANT.SoC style naming, on iOS of course. */
#define kKernelPathOld "/mach_kernel"

