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
#include "CDBBasicTypes.h"
#include <Platform/Apple/BootArgs.h>

/*!
  @function CDBInitKernelBootArguments
  @abstract Allocates a local XNUBootArgs instance, which can be accessed by CoreDarwinBoot and other services within the same UEFI Application
  @result Returns true if the operation was successful
 */
extern bool CDBInitKernelBootArguments(void);

/*!
  @function CDBAddKernelExtensionToBoot
  @abstract Allocates a BootKernelExtensionEntry instance & adds it to the DeviceTree
  @result Returns true if the operation was successful
 */
extern bool CDBAddKernelExtensionToBoot(const UInt8 *infoPlist, const UInt32 plistSize, const UInt8 *exec, const UInt32 execSize, const char *pathToBundle);
