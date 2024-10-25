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

#ifndef PLATFORM_USERTEST
#include "CDBBasicTypes.h"
#endif

#if PLATFORM_ACPI == 1
#include <Platform/ACPI/ACPI.h>
#endif

#if PLATFORM_EFI == 1
#include <Platform/EFI/EFITypes.h>
#include <Platform/EFI/GUID.h>
#endif

#if PLATFORM_SMBIOS == 1
#include <Platform/SMBIOS/SMBIOS.h>
#endif

#include "BootArgs.h"
#include "CPUInfo.h"
#include "DeviceTree.h"

/* STANDARD CoreDarwinBoot FUNCTIONS */

#define CDB_LOG_POLICY_ERROR (1 << 0)
#define CDB_LOG_POLICY_WARNING (1 << 1)
#define CDB_LOG_POLICY_INFORMATION (1 << 2)
#define CDB_LOG_POLICY_SPAM (1 << 3)
#define CDB_LOG_POLICY_DEBUG (1 << 4)

extern void CDBAssert(wchar_t * fmt, ...);
extern void CDBLog(UInt32 Type, wchar_t *msg, ...);
extern void *CDBAllocateMemory(const UInt32 size);
extern void CDBReleaseMemory(void *p);

#if PLATFORM_EFI == 1
extern bool CDBInitializeUEFI(EFI_SYSTEM_TABLE *Sys);
extern bool CDBGUIDMatches(EFI_GUID * a, EFI_GUID * b);
#endif
