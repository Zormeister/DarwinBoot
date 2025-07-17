// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/* These are actually just Carbon types. I've put 'HFS' as a prefix for clarification. */

struct {
    SInt16 V;
    SInt16 H;
} typedef HFSPoint;

struct {
    SInt16 Top;
    SInt16 Left;
    SInt16 Bottom;
    SInt16 Right;
} typedef HFSRect;

typedef UInt32 HFSFourCharCode;
typedef HFSFourCharCode HFSOSType;

struct {
    HFSOSType FileType;
    HFSOSType FileCreator;
    UInt16 FinderFlags;
    HFSPoint Location;
    UInt16 Reserved;
} typedef HFSFileInfo;