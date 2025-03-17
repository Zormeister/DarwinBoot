// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/EFI/EFITypes.h>
#include <Platform/EFI/Protocols/SimpleText.h>

#pragma mark EFI_MEMORY_ATTRIBUTES_TABLE

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID \
  {0xdcfa911d, 0x26eb, 0x469f, \
    {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20}}

struct {
    UInt32 Version;
    UInt32 NumberOfEntries;
    UInt32 DescriptorSize;
    UInt32 Flags;
    EFI_MEMORY_DESCRIPTOR Descriptors[];
} typedef EFI_MEMORY_ATTRIBUTES_TABLE;

#define EFI_MEMORY_ATTRIBUTES_FLAGS_RT_FORWARD_CONTROL_FLOW_GUARD  0x1

/* UEFI apps have R/W access to the FDT */
#define EFI_DTB_TABLE_GUID \
  {0xb1b621d5, 0xf19c, 0x41a5, \
    {0x83, 0x0b, 0xd9, 0x15, 0x2c, 0x69, 0xaa, 0xe0}}

#pragma mark EFI_SYSTEM_TABLE

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_110_SYSTEM_TABLE_REVISION ((2<<16) | (110))
#define EFI_2_100_SYSTEM_TABLE_REVISION ((2<<16) | (100))
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_110_SYSTEM_TABLE_REVISION

typedef struct _EFI_BOOT_SERVICES EFI_BOOT_SERVICES;
typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

struct _EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER Header;
    wchar_t * FirmwareVendor;
    UInt32 FirmwareRevision;
    EFI_HANDLE ConInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UInt32 NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTables;
};

typedef struct _EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

#pragma mark EFI_BOOT_SERVICES

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

struct _EFI_BOOT_SERVICES {
    EFI_TABLE_HEADER Header;
    
    /* Task Priority svcs. EFI 1.0+ */
    EFI_TPL (*RaiseTPL)(EFI_TPL NewTpl);
    void (*RestoreTPL)(EFI_TPL OldTpl);
    
    /* memory svcs */
    EFI_STATUS (*AllocatePages)(EFI_ALLOCATE_TYPE Type, EFI_MEMORY_TYPE MemoryType, UInt32 NumPages, EFI_PHYSICAL_ADDRESS *AllocatedMem);
    EFI_STATUS (*FreePages)(EFI_PHYSICAL_ADDRESS MemAddr, UInt32 PageCount);
    EFI_STATUS (*GetMemoryMap)(UIntN *MemoryMapSize, EFI_MEMORY_DESCRIPTOR *MemoryMap, UIntN *OutKey, UIntN *DescriptorSize, UInt32 *DescriptorVersion);
    EFI_STATUS (*AllocatePool)(EFI_MEMORY_TYPE PoolType, UIntN Size, void **Buffer);
    EFI_STATUS (*FreePool)(void *Buffer);

    /* others */
    EFI_STATUS (*CreateEvent)(UInt32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, void *NotifyContext, EFI_EVENT *Event);
    EFI_STATUS (*SetTimer)(EFI_EVENT Event, EFI_TIMER_DELAY Type, UInt64 TriggerTime);
    EFI_STATUS (*WaitForEvent)(UIntN NumberOfEvents, EFI_EVENT *Event, UIntN *Index);
    EFI_STATUS (*SignalEvent)(EFI_EVENT Event);
    EFI_STATUS (*CloseEvent)(EFI_EVENT Event);
    EFI_STATUS (*CheckEvent)(EFI_EVENT Event);

    /* Protocol Interfaces */
    EFI_STATUS (*InstallProtocolInterface)(EFI_HANDLE *Handle, EFI_GUID *Protocol, EFI_INTERFACE_TYPE InterfaceType, void *Interface);
    EFI_STATUS (*ReinstallProtocolInterface)(EFI_HANDLE Handle, EFI_GUID *Protocol, void *OldInterface, void *NewInterface);
    EFI_STATUS (*UninstallProtocolInterface)(EFI_HANDLE Handle, EFI_GUID *Protocol, void *Interface);
    EFI_STATUS (*HandleProtocol)(EFI_HANDLE Handle, EFI_GUID *Protocol, void **Interface);
    void *Reserved;
    EFI_STATUS (*RegisterProtocolNotify)(EFI_GUID *Protocol, EFI_EVENT Event, void **Registration);
};

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION