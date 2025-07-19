// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Tables/Header.h>
#include <Platform/EFI/Types.h>

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION  EFI_SPECIFICATION_VERSION

enum {
    EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL = 0x1,
    EFI_OPEN_PROTOCOL_GET_PROTOCOL = 0x2,
    EFI_OPEN_PROTOCOL_TEST_PROTOCOL = 0x4,
    EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER = 0x8,
    EFI_OPEN_PROTOCOL_BY_DRIVER = 0x10,
    EFI_OPEN_PROTOCOL_EXCLUSIVE = 0x20
};

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
} typedef EFI_BOOT_SERVICES;
