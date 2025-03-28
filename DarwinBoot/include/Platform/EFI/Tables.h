// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "builtins.h"
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/EFI/EFITypes.h>
#include <Platform/EFI/Protocols/SimpleText.h>
#include <Platform/EFI/Protocols/DevicePath.h>

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

struct {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UInt32 Attributes;
    UInt32 OpenCount;
} typedef EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

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
    EFI_STATUS (*LocateHandle)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID *Protocol, void *SearchKey, UIntN *BufferSize, EFI_HANDLE *Buffer);
    EFI_STATUS (*LocateDevicePath)(EFI_GUID *Protocol, EFI_DEVICE_PATH_PROTOCOL **DevicePath, EFI_HANDLE *Device);
    EFI_STATUS (*InstallConfigurationTable)(EFI_GUID *GUID, void *Table);

    // UEFI Image Services
    EFI_STATUS (*LoadImage)(bool BootPolicy, EFI_HANDLE ParentImageHandle, EFI_DEVICE_PATH_PROTOCOL *DevicePath, void *SourceBuffer, UIntN SourceSize, EFI_HANDLE *ImageHandle);
    EFI_STATUS (*StartImage)(EFI_HANDLE ImageHandle, UIntN *ExitDataSize, wchar_t **ExitData);
    EFI_STATUS (*Exit)(EFI_HANDLE ImageHandle, EFI_STATUS ExitStatus, UIntN ExitDataSize, wchar_t **ExitData);
    EFI_STATUS (*UnloadImage)(EFI_HANDLE ImageHandle);
    EFI_STATUS (*ExitBootServices)(EFI_HANDLE Handle, UIntN MapKey);

    EFI_STATUS (*GetNextMonotonicCount)(UInt64 *Count);
    EFI_STATUS (*Stall)(UInt64 Microseconds);
    EFI_STATUS (*SetWatchdogTimer)(UIntN Timeout, UInt64 WatchdogCode, UInt16 DataSize, wchar_t *WatchdogData);

    EFI_STATUS (*ConnectController)(EFI_HANDLE ControllerHandle, EFI_HANDLE DriverImageHandle, EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath, bool Recursive);
    EFI_STATUS (*DisconnectController)(EFI_HANDLE ControllerHandle, EFI_HANDLE DriverImageHandle, EFI_HANDLE ChildHandle);

    EFI_STATUS (*OpenProtocol)(EFI_HANDLE Handle, EFI_GUID *Protocol, void **Interface, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle, UInt32 Attributes);
    EFI_STATUS (*CloseProtocol)(EFI_HANDLE Handle, EFI_GUID *Protocol, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle);
    EFI_STATUS (*OpenProtocolInformation)(EFI_HANDLE Handle, EFI_GUID *Protocol, EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer, UIntN *EntryCount);

    EFI_STATUS (*ProtocolsPerHandle)(EFI_HANDLE Handle, EFI_GUID ***ProtocolBuffer, UIntN *ProtocolBufferCount);
    EFI_STATUS (*LocateHandleBuffer)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID *Protocol, void *SearchKey, UIntN *NumHandles, EFI_HANDLE **Handles);
    EFI_STATUS (*LocateProtocol)(EFI_GUID *Protocol, void *Registration, void **Interface);
    EFI_STATUS (*InstallMultipleProtocolInterfaces)(EFI_HANDLE *Handle, ...);
    EFI_STATUS (*UninstallMultipleProtocolInterfaces)(EFI_HANDLE Handle, ...);

    EFI_STATUS (*CalculateCrc32)(void *Data, UIntN DataSize, UInt32 *Crc32);

    void (*CopyMem)(void *Destination, void *Source, UIntN Length);
    void (*SetMem)(void *Buffer, UIntN Size, UInt8 Value);
    EFI_STATUS (*CreateEventEx)(UInt32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, const void *NotifyContext, const EFI_GUID *EventGroup, EFI_EVENT *Event);
};

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

enum {
    EFI_VARIABLE_NON_VOLATILE = 0x00000001,
    EFI_VARIABLE_BOOTSERVICE_ACCESS = 0x00000002,
    EFI_VARIABLE_RUNTIME_ACCESS = 0x00000004,
    EFI_VARIABLE_HARDWARE_ERROR_RECORD = 0x00000008,
    EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS = 0x00000020,
    EFI_VARIABLE_APPEND_WRITE = 0x00000040,
    EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS = 0x00000080,
};

struct {
    UInt8 Type;
    UInt32 IdSize;
    UInt8 Id[] __counted_by(IdSize);
} typedef EFI_VARIABLE_AUTHENTICATION_3_CERT_ID;

enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} typedef EFI_RESET_TYPE;

struct {
    EFI_GUID CapsuleGuid;
    UInt32 HeaderSize;
    UInt32 Flags;
    UInt32 CapsuleImageSize;
} typedef EFI_CAPSULE_HEADER;

struct {
    UInt32 CapsuleArrayNumber;
    EFI_CAPSULE_HEADER *CapsulePtr[] __counted_by(CapsuleArrayNumber);
} typedef EFI_CAPSULE_TABLE;

struct {
    UInt64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    } Union;
} typedef EFI_CAPSULE_BLOCK_DESCRIPTOR;

struct _EFI_RUNTIME_SERVICES {
    EFI_TABLE_HEADER Header;

    EFI_STATUS (*GetTime)(EFI_TIME *Time, EFI_TIME_CAPABILITIES *Capabilities);
    EFI_STATUS (*SetTime)(EFI_TIME *Time);
    EFI_STATUS (*GetWakeupTime)(bool *Enabled, bool *Pending, EFI_TIME *Time);
    EFI_STATUS (*SetWakeupTime)(bool Enabled, EFI_TIME *Time);

    EFI_STATUS (*SetVirtualAddressMap)(UIntN MemoryMapSize, UIntN DescriptorSize, UInt32 DescriptorVersion, EFI_MEMORY_DESCRIPTOR *VirtualMap);
    EFI_STATUS (*ConvertPointer)(UIntN DebugDisposition, void **Address);

    EFI_STATUS (*GetVariable)(wchar_t *VariableName, EFI_GUID *VendorGuid, UInt32 *Attributes, UIntN *DataSize, void *Data);
    EFI_STATUS (*GetNextVariableName)(UIntN *VariableNameSize, wchar_t *VariableName, EFI_GUID *VendorGuid);
    EFI_STATUS (*SetVariable)(wchar_t *VariableName, EFI_GUID *VendorGuid, UInt32 Attributes, UIntN DataSize, void *Data);

    EFI_STATUS (*GetNextHighMonotonicCount)(UInt32 *HighCount);
    void (*ResetSystem)(EFI_RESET_TYPE ResetType, EFI_STATUS ResetStatus, UIntN DataSize, void *ResetData);

    EFI_STATUS (*UpdateCapsule)(EFI_CAPSULE_HEADER **CapsuleHeaderArray, UIntN CapsuleCount, EFI_PHYSICAL_ADDRESS ScatterGatherList);
    EFI_STATUS (*QueryCapsuleCapabilities)(EFI_CAPSULE_HEADER **capsuleHeaderArray, UIntN CapsuleCount, UInt64 *MaxCapsuleSize, EFI_RESET_TYPE *ResetType);

    EFI_STATUS (*QueryVariableInfo)(UInt32 Attributes, UInt64 *MaxVariableStorageSize, UInt64 *RemainingVariableStorageSize, UInt64 *MaximumVariableSize);
};

#define EFI_OPTIONAL_PTR 0x00000001

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000
