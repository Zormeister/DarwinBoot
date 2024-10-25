// Copyright © 2024 Zormeister. All rights reserved.

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

/* as of rn DarwinBoot is UEFI-coded but independence isn't impossible */
/* i do infact have to learn ARM asm for that, so that's nice */
/* also- drivers? god damn im going to SUFFER writing those, but eh */
/* CoreDarwinBoot can be expanded for ARM UEFI-less platforms to have a driver system. */
/* sounds cursed but that's the only way to get an ARM UEFI-less platform going */
/* for reference, look at Das U-Boot */
/* targets for now for ARM UEFI-less should be QEMU ARM64 boards & BCM2837 RPi devices since those are devices i have access to */
/* (no qualcomm 4 u) */
/* it also seems like more and more ARM devices are using UEFI with the advent of Copilot+ devices */
/* so maybe in a few years this won't be needed */
#define PERIPHERAL_BASE         0x20000000
#define PERIPHERAL_TOP          0x20FFFFFF
#define PERIPHERAL_VIRTUAL_BASE 0xF2000000
#define PERIPHERAL_VIRTUAL_TOP  0xF2FFFFFF
#define PERIPHERAL_BUS_BASE     0x7E000000
#define PERIPHERAL_BUS_TOP      0x7EFFFFFF
