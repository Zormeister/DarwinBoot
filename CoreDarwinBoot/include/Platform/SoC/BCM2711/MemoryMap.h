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

/* BCM2711: the addresses go through the VideoCore & ARM MMU before reaching our phys addrs */

#define ADDRESS_BITS 35
#define ADDRESS_BITS_ALT 32

#define SDRAM_BASE 0x000000000

/* VRAM base is determind by VRAM size in the Pi config. */
/* vramBase = vramTop - vramSize */
/* TODO: interpret config.txt */
#define VRAM_TOP 0x040000000

/* DMA engines use the legacy 32-bit addresses */

#define LEGACY_PERIPHERAL_BASE 0x7C000000

