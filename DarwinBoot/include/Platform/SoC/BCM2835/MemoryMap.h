// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

/* BCM2835: the addresses go through the VideoCore & ARM MMU before reaching our phys addrs */

#define ADDRESS_BITS 32

/* physical base? */
#define KERNEL_VIRTUAL_BASE 0xC0000000
#define KERNEL_VIRTUAL_TOP  0xEFFFFFFF

#define SDRAM_BASE 0x00000000 /* TODO: workout SDRAM size for BCM2835 targets, or have it specified as part of platform config */

/* bus addresses go through the DMA controller, TODO: figure out how the DMA controller works */

/* This is the Pi 2 and Pi 3 MMIO base. */
#if BOARD_BCM2835_PI2
#define PERIPHERAL_MMIO_BASE 0x3F000000
#else
#define PERIPHERAL_MMIO_BASE 0x20000000
#endif
