// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "CDBBasicTypes.h"
#include <Platform/Apple/BootArgs.h>
#include <CoreDarwinBoot/DeviceTree.h>

/*!
  @function CDBInitKernelBootArguments
  @abstract Allocates a local XNUBootArgs instance, which can be accessed by CoreDarwinBoot and other services within the same UEFI Application
  @result Returns true if the operation was successful
 */
extern bool CDBInitKernelBootArguments(void);

/*!
  @function CDBAddKernelExtensionToBoot
  @abstract Allocates a BootKernelExtensionEntry instance & adds it to the DeviceTree
  @param DeviceTree  The DeviceTree to add the kext to
  @param InfoPlist   The in-memory copy of the kext's Info.plist file.
  @param PlistSize   The size of the in-memory copy of the kext's Info.plist file.
  @result Returns true if the operation was successful
 */
extern bool CDBAddKernelExtensionToBoot(CDBDeviceTree *DeviceTree, const UInt8 *InfoPlist, const UInt32 PlistSize, const UInt8 *Exec, const UInt32 ExecSize, const char *PathToBundle);

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
