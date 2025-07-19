// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Protocols/SimpleText.h>
#include <Platform/EFI/Tables/BootServices.h>
#include <Platform/EFI/Tables/ConfigurationTable.h>
#include <Platform/EFI/Tables/RuntimeServices.h>

#define EFI_SYSTEM_TABLE_SIGNATURE      0x5453595320494249
#define EFI_2_110_SYSTEM_TABLE_REVISION ((2 << 16) | (110))
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2 << 16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION  ((2 << 16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION  ((2 << 16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION  ((2 << 16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION  ((2 << 16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION  ((2 << 16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION  ((2 << 16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION  ((2 << 16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION  ((2 << 16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION  ((2 << 16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION  ((2 << 16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION  ((2 << 16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION  ((1 << 16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION  ((1 << 16) | (02))
#define EFI_SPECIFICATION_VERSION       EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION       EFI_2_110_SYSTEM_TABLE_REVISION

struct _EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER Header;
    wchar_t *FirmwareVendor;
    UInt32 FirmwareRevision;
    EFI_HANDLE ConInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UInt32 NumberOfConfigurationTables;
    EFI_CONFIGURATION_TABLE *ConfigurationTables;
} typedef EFI_SYSTEM_TABLE;
