// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

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

extern void CDBAssert(const char * fmt, ...);
extern void CDBLog(UInt32 Type, const char *msg, ...);
extern void *CDBAllocateMemory(const UInt32 size);
extern void CDBReleaseMemory(void *p);

#if PLATFORM_EFI == 1
extern bool CDBInitializeUEFI(EFI_SYSTEM_TABLE *Sys);
extern bool CDBGUIDMatches(EFI_GUID * a, EFI_GUID * b);
extern EFI_CONFIGURATION_TABLE *CDBEFIGetConfigurationTable(EFI_GUID *Guid);
#endif
