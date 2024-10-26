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

/* 64-bit */
#define MSR_P5_TSC 0x00000010

#define MSR_MPERF 0x000000E7
#define MSR_APERF 0x000000E8

#define MSR_TSC_RATIO 0xC0000104
#define TSC_RATE_INTEGER_SHIFT 32
#define TSC_RATE_INTEGER_MASK (1 << 32) | (1 << 33) | (1 << 33) | (1 << 34) | (1 << 35) | (1 << 36) | (1 << 37) | (1 << 38) | (1 << 38) | (1 << 39)

#define MSR_AMD_HW_CONFIG 0xC0010015
#define AMD_HW_CONFIG_TSC_LOCK (1 << 21)
