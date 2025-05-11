// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/ACPI/ACPI.h>
#include <Platform/EFI/EFI.h>

EFI_GUID gAcpiEfiConfigurationTableGuid = ACPI_TABLE_GUID;
EFI_GUID gAcpiV2EfiConfigurationTableGuid = EFI_ACPI_20_TABLE_GUID;
