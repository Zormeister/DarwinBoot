// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#include <Platform/EFI/Types.h>
#include <Platform/EFI/Tables.h>
#include <Platform/EFI/Protocols.h>

extern EFI_SYSTEM_TABLE *ST;
extern EFI_BOOT_SERVICES *BS;
extern EFI_RUNTIME_SERVICES *RT;
extern EFI_LOADED_IMAGE_PROTOCOL *LIP;

/*!
 @function EFIInitialize

 @abstract Initializes the UEFI platform components of DarwinBoot.

 @param ImageHandle   Our own handle; first parameter of the entry point.
 @param SystemTable   The EFI System Table provided in the entry point.
 */
extern bool EFIInitialize(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable);

extern bool EFICompareGUID(EFI_GUID * a, EFI_GUID * b);

extern EFI_CONFIGURATION_TABLE *CDBEFIGetConfigurationTable(EFI_GUID *Guid);
