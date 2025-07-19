// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Types.h>

#define EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID \
    { 0x379be4e, 0xd706, 0x437d,                \
        { 0xb0, 0x37, 0xed, 0xb8, 0x2f, 0xb7, 0x72, 0xa4 } }

extern EFI_GUID gEfiDevicePathUtilitiesProtocolGuid;

typedef struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL EFI_DEVICE_PATH_UTILITIES_PROTOCOL;

struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL {
    UIntN (*GetDevicePathSize)(const EFI_DEVICE_PATH_PROTOCOL *DevicePath);
    EFI_DEVICE_PATH_PROTOCOL *(*DuplicateDevicePath)(const EFI_DEVICE_PATH_PROTOCOL *DevicePath);
    EFI_DEVICE_PATH_PROTOCOL *(*AppendDevicePath)(const EFI_DEVICE_PATH_PROTOCOL *Src1, const EFI_DEVICE_PATH_PROTOCOL *Src2);
    EFI_DEVICE_PATH_PROTOCOL *(*AppendDeviceNode)(const EFI_DEVICE_PATH_PROTOCOL *DevicePath, const EFI_DEVICE_PATH_PROTOCOL *DeviceNode);
    EFI_DEVICE_PATH_PROTOCOL *(*AppendDevicePathInstance)(const EFI_DEVICE_PATH_PROTOCOL *DevicePath, const EFI_DEVICE_PATH_PROTOCOL *DeviceNode);
    EFI_DEVICE_PATH_PROTOCOL *(*GetNextDevicePathInstance)(EFI_DEVICE_PATH_PROTOCOL **DevicePathInstance, UIntN *DevicePathInstanceSize);
    bool (*IsDevicePathMultiInstance)(const EFI_DEVICE_PATH_PROTOCOL *DevicePath);
    EFI_DEVICE_PATH_PROTOCOL *(*CreateDeviceNode)(UInt8 NodeType, UInt8 NodeSubType, UInt16 NodeLength);
};
