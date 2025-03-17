// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

#ifndef PLATFORM_USERTEST
#include "CDBBasicTypes.h"
#endif

#if PLATFORM_ACPI == 1
#include <Platform/ACPI/ACPI.h>
#endif

#if PLATFORM_EFI == 1
#include <Platform/EFI/EFI.h>
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

void CDBLogv(const char *fmt, va_list va);
void CDBLog(const char *fmt, ...);

extern void *CDBAllocateMemory(const UInt32 size);
extern void CDBFreeMemory(void *p);

extern void panic(const char *fmt, ...);

// Shooooould be on the EFI Partition and Darwin partition.
// UEFI on-EFI loader should be on the lookout for bootable partitions.
#define DARWINBOOT_CONFIG_PATH "/Library/Preferences/SystemConfiguration/com.zormeister.DarwinBoot.plist"

#if AUTORAMDISK_PB

// ProjectBuilder integration?
// I need to work out how to sign/chunklist DMGs ffs
#define AUTORAMDISK_PATH "\\Library\\Caches\\com.zormeister.ProjectBuilder\\DarwinRAMDisk.dmg"
#define AUTORAMDISK_DEV_PATH "\\Library\\Caches\\com.zormeister.ProjectBuilder\\DarwinRAMDisk.development.dmg"
#else
#define AUTORAMDISK_PATH "\\com.apple.recovery.boot\\BaseSystem.dmg"
#define AUTORAMDISK_DEV_PATH "\\com.apple.recovery.boot\\InternalSystem.dmg" // i have no idea if this is actually the case
#endif

#if PLATFORM_EFI == 1
extern bool CDBInitializeUEFI(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *Sys);
extern bool CDBGUIDMatches(EFI_GUID * a, EFI_GUID * b);
extern EFI_CONFIGURATION_TABLE *CDBEFIGetConfigurationTable(EFI_GUID *Guid);
#endif
