// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "CDBBasicTypes.h"
#include <Platform/Apple/BootArgs.h>

/*!
  @function CDBInitKernelBootArguments
  @abstract Allocates a local XNUBootArgs instance, which can be accessed by CoreDarwinBoot and other services within the same UEFI Application
  @result Returns true if the operation was successful
 */
extern bool CDBInitKernelBootArguments(void);

/*!
  @function CDBAddKernelExtensionToBoot
  @abstract Allocates a BootKernelExtensionEntry instance & adds it to the DeviceTree
  @result Returns true if the operation was successful
 */
extern bool CDBAddKernelExtensionToBoot(const UInt8 *infoPlist, const UInt32 plistSize, const UInt8 *exec, const UInt32 execSize, const char *pathToBundle);

struct {
    UInt64 BaseAddress; // This assumes we're purely 64-bit.
    UInt16 Rotation; // Valid values: 0, 90, 180, 270, 360
    UInt16 PixelFormat;
    UInt32 Width;
    UInt32 Height;
} typedef CDBVideoInfo;

extern bool CDBBootArgsSetVideoInfo(CDBVideoInfo *VideoInfo);

#if __x86_64__

struct {
    UInt64 BaseAddress;
} typedef CDBPCIInfo;

extern bool CDBBootArgsSetPCIInfo();

#endif