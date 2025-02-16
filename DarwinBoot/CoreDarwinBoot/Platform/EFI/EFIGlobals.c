// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/ACPI/ACPI.h>

#if PLATFORM_EFI == 1

#if PLATFORM_SMBIOS == 1
EFI_GUID gSmbiosTableGuid = SMBIOS_TABLE_GUID;
EFI_GUID gEfiSmbiosV3TableGuid = SMBIOS3_TABLE_GUID;
#endif

#endif