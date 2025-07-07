// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

struct HFSUniStr255 {
    UInt16 Length;
    wchar_t Unicode[255];
} typedef HFSUniStr255;
