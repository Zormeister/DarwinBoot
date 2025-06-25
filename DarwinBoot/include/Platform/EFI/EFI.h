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

/*!
 @function EFIGuidMatches

 @abstract Compares GUIDs

 @param a   GUID to be compared against
 @param b   GUID to be compared with

 @result Returns true if the GUIDs are the same.
 */
extern bool EFIGuidMatches(EFI_GUID * a, EFI_GUID * b);


/*!
 @function EFIGetConfigurationTable

 @abstract Finds a configuration table from the system table.

 @param Guid   The GUID of the requested table.

 @result Returns the VendorTable field of an EFI_CONFIGURATION_TABLE.
 */
extern void *EFIGetConfigurationTable(EFI_GUID *Guid);
