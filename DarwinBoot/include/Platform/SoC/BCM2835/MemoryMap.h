// Copyright © 2024 Zormeister.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

/* BCM2835: the addresses go through the VideoCore & ARM MMU before reaching our phys addrs */

#define ADDRESS_BITS 32

/* physical base? */
#define KERNEL_VIRTUAL_BASE 0xC0000000
#define KERNEL_VIRTUAL_TOP  0xEFFFFFFF

#define SDRAM_BASE 0x00000000 /* TODO: workout SDRAM size for BCM2835 targets, or have it specified as part of platform config */

/* bus addresses go through the DMA controller, TODO: figure out how the DMA controller works */

#define PERIPHERAL_MMIO_BASE 0x3F000000