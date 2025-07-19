// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

#define FLASH_BASE 0x00000000ULL

/* FDT is at this address, we should read from it and fetch the memory-map addresses */
#define SDRAM_BASE 0x40000000ULL

/* QEMU dumps to a blob and decleares the whole region usable. I'm going to shift the base established by the allocator. */
#define FDT_SIZE 0x40000000ULL
