// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

#define KERNEL_RSVD_BASE 0x80000

#define SDRAM_BASE 0x00000000
#define SDRAM_BASE_SIZE 512 * 1024 * 1024 /* 512 MiB */
#define SDRAM_EXTENDED_BASE 0x40000000

#define PAGE_SIZE 4096

/* This is the maximum amount of RAM one can have. */
#define MAX_MEMSIZE (8 * 1024 * 1024 * 1024)

#define MAX_PAGES MAX_MEMSIZE / PAGE_SIZE

/* DMA engines use the legacy 32-bit addresses */
#define DMA_PERIPHERAL_BASE 0x7C000000

#define PERIPHERAL_MMIO_BASE 0xFE000000

/* The Pi loader put the kernel data section at 0x18800000 IIRC. */

/* 
 * Where should I even load XNU? Upper memory regions?
 * I need a region where XNU can safely initialize and get itself ready, so a space >= 600MB seems reasonable.
 * With the fact we barely have any kernel extensions for ARM64 that aren't Apple kexts it'd be safe to load XNU 
 * in some small contained memory region.
 */