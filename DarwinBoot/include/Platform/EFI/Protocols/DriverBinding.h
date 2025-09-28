// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_PROTOCOLS_DRIVERBINDING_H__
#define __PLATFORM_EFI_PROTOCOLS_DRIVERBINDING_H__

#include <Platform/EFI/Protocols/DevicePath.h>
#include <Platform/EFI/Types.h>

#define EFI_DRIVER_BINDING_PROTOCOL_GUID \
    { 0x18A031AB, 0xB443, 0x4D1A,        \
        { 0xA5, 0xC0, 0x0C, 0x09, 0x26, 0x1E, 0x9F, 0x71 } }

extern EFI_GUID gEfiDriverBindingProtocolGuid;

typedef struct _EFI_DRIVER_BINDING_PROTOCOL EFI_DRIVER_BINDING_PROTOCOL;

struct _EFI_DRIVER_BINDING_PROTOCOL {
    EFI_STATUS (*Supported)(EFI_DRIVER_BINDING_PROTOCOL *This, EFI_HANDLE ControllerHandle, EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath);
    EFI_STATUS (*Start)(EFI_DRIVER_BINDING_PROTOCOL *This, EFI_HANDLE ControllerHandle, EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath);
    EFI_STATUS (*Stop)(EFI_DRIVER_BINDING_PROTOCOL *This, EFI_HANDLE ControllerHandle, UIntN *NumberOfChildren, EFI_HANDLE *ChildHandleBuffer);
    UInt32 Version;
    EFI_HANDLE ImageHandle;
    EFI_HANDLE DriverBindingHandle;
};

#endif /* __PLATFORM_EFI_PROTOCOLS_DRIVERBINDING_H__ */
