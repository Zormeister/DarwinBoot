// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

/* BCM2711: the addresses go through the VideoCore & ARM MMU before reaching our phys addrs */

#define SDRAM_BASE 0x000000000

/* This is the maximum amount of RAM one can have. */
#define MAX_MEMSIZE (8 * 1024 * 1024 * 1024)

#define MAX_PAGES MAX_MEMSIZE / PAGE_SIZE

/* VRAM base is determind by VRAM size in the Pi config. */
/* vramBase = vramTop - vramSize */
/* TODO: interpret config.txt */
#define VRAM_TOP 0x040000000

/* DMA engines use the legacy 32-bit addresses */
#define DMA_PERIPHERAL_BASE 0x7C000000

#define PERIPHERAL_MMIO_BASE 0xFE000000

