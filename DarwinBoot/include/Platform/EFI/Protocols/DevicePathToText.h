// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Types.h>

#define EFI_DEVICE_PATH_TO_TEXT_PROTOCOL_GUID \
    { 0x8b843e20, 0x8132, 0x4852,             \
        { 0x90, 0xcc, 0x55, 0x1a, 0x4e, 0x4a, 0x7f, 0x1c } }

extern EFI_GUID gEfiDevicePathToTextProtocolGuid;

typedef struct _EFI_DEVICE_PATH_TO_TEXT_PROTOCOL EFI_DEVICE_PATH_TO_TEXT_PROTOCOL;

struct _EFI_DEVICE_PATH_TO_TEXT_PROTOCOL {
    wchar_t *(*ConvertDeviceNodeToText)(const EFI_DEVICE_PATH_PROTOCOL *DeviceNode, bool DisplayOnly, bool AllowShortcuts);
    wchar_t *(*ConvertDevicePathToText)(const EFI_DEVICE_PATH_PROTOCOL *DeviceNode, bool DisplayOnly, bool AllowShortcuts);
};
