// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/DeviceTree.h>
#include <Platform/Apple/BootArgs.h>

typedef struct _CDBBootArgs *CDBBootArgsRef;

bool CDBBootArgsAppendCommandLine(CDBBootArgsRef Args, const char *BootArgument);

struct {
    UInt64 BaseAddress; // This assumes we're purely 64-bit.
    UInt16 Rotation;    // Valid values: 0, 90, 180, 270, 360
    UInt16 PixelFormat;
    UInt32 Width;
    UInt32 Height;
} typedef CDBVideoInfo;

extern bool CDBBootArgsSetVideoInfo(CDBBootArgsRef BootArgs, CDBVideoInfo *VideoInfo);

#if __x86_64__

struct {
    UInt64 BaseAddress;
} typedef CDBPCIInfo;

extern bool CDBBootArgsSetPCIInfo();

/* WIP - ECAM data served to PE should be grabbed from MCFG. */

#endif
