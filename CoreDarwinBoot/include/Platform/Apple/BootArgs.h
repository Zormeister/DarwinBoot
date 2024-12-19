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
#include <CoreDarwinBoot/CDBBasicTypes.h>

#if TARGET_ARM32 || TARGET_ARM64
#include "BootArgsARM.h"
#endif

#if TARGET_X64 || TARGET_IA32
#include "BootArgsX86.h"
#endif

/* apparently you can also load Dexts this way, interesting. */
struct {
    UInt32 InfoPlistAddr;
    UInt32 InfoPlistSize;
    UInt32 ExecAddress;
    UInt32 ExecSize;
    UInt32 BundlePathAddr;
    UInt32 BundlePathLength;
} typedef BootKernelExtensionEntry;
