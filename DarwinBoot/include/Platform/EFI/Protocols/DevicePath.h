// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/EFITypes.h>

#define EFI_DEVICE_PATH_PROTOCOL_GUID \
  {0x09576e91,0x6d3f,0x11d2,\
    {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

enum {
    EFI_DEVICE_PATH_TYPE_HARDWARE = 1,
    EFI_DEVICE_PATH_TYPE_ACPI,
    EFI_DEVICE_PATH_TYPE_MESSAGING_DEVICE,
    EFI_DEVICE_PATH_TYPE_MEDIA_DEVICE,
    EFI_DEVICE_PATH_TYPE_BIOS_BOOT_SPEC,
};

enum {
    EFI_HARDWARE_PATH_SUBTYPE_PCI = 1,
};

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
} typedef EFI_DEVICE_PATH_PROTOCOL;

struct {
    UInt8 Type;
    UInt8 SubType;
    UInt8 Length[2];
    UInt8 PCIFunction;
    UInt8 PCIDevice;
} typedef EFI_DEVICE_PATH_PCI_PROTOCOL;