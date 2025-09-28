// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_RUNTIMESERVICES_H__
#define __PLATFORM_EFI_TABLES_RUNTIMESERVICES_H__

#include <Platform/EFI/Tables/Header.h>
#include <Platform/EFI/Types.h>

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION  EFI_SPECIFICATION_VERSION

enum {
    EFI_VARIABLE_NON_VOLATILE = 0x00000001,
    EFI_VARIABLE_BOOTSERVICE_ACCESS = 0x00000002,
    EFI_VARIABLE_RUNTIME_ACCESS = 0x00000004,
    EFI_VARIABLE_HARDWARE_ERROR_RECORD = 0x00000008,
    EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS = 0x00000020,
    EFI_VARIABLE_APPEND_WRITE = 0x00000040,
    EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS = 0x00000080,
};

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
} typedef EFI_RUNTIME_SERVICES;

#define EFI_OPTIONAL_PTR 0x00000001

#endif /* __PLATFORM_EFI_TABLES_RUNTIMESERVICES_H__ */
