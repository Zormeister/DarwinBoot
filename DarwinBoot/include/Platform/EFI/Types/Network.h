// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_NETWORK_H__
#define __PLATFORM_EFI_TYPES_NETWORK_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    UInt8 Address[32];
} typedef EFI_MAC_ADDRESS;

struct {
    UInt8 Address[4];
} typedef EFI_IPv4_ADDRESS;

struct {
    UInt8 Address[16];
} typedef EFI_IPv6_ADDRESS;

union {
    EFI_IPv4_ADDRESS IPv4;
    EFI_IPv6_ADDRESS IPv6;
} typedef EFI_IP_ADDRESS;

#endif /* __PLATFORM_EFI_TYPES_NETWORK_H__ */
