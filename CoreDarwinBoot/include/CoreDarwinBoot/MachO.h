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
#include "CDBBasicTypes.h"

/* 0xfeedface & 0xcefaedfe */
#define MACH_MAGIC 0xFEEDFACE
#define MACH_CIGAM 0xCEFAEDFE

/* 0xfeedface & 0xcefaedfe */
#define MACH_MAGIC_64 0xFEEDFACF
#define MACH_CIGAM_64 0xCFFAEDFE

/* Mach-O header go brrrr */
struct {
    UInt32 Magic;
    UInt32 CpuType;
    UInt32 CpuSubType;
    UInt32 FileType;
    UInt32 LoadCommandCount;
    UInt32 LoadCommandsSize;
    UInt32 Flags;
} typedef MachOHeader;

struct {
    UInt32 Magic;
    UInt32 CpuType;
    UInt32 CpuSubType;
    UInt32 FileType;
    UInt32 LoadCommandCount;
    UInt32 LoadCommandsSize;
    UInt32 Flags;
    UInt32 Rsvd;
} typedef MachOHeader64;

/* https://github.com/apple-oss-distributions/cctools/blob/cctools-1010.6/include/mach/machine-cctools.h#L139 */
enum {
    MachAbiX64 = 0x1000000,
    MachCpuTypeVax = 1,
    MachCpuTypeRomp = 2,
    MachCpuTypeI386 = 7,
    MachCpuTypeX86_64 = MachCpuTypeI386 | MachAbiX64,
    MachCpuTypeARM = 12,
    MachCpuTypeARM64 = MachCpuTypeARM | MachAbiX64,
};