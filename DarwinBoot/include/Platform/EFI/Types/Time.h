// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    UInt16 Year;
    UInt8 Month;
    UInt8 Day;
    UInt8 Hour;
    UInt8 Minute;
    UInt8 Second;
    UInt8 Padding;
    UInt32 Nanosecond;
    SInt32 TimeZone;
    UInt8 Daylight;
    UInt8 Padding2;
} typedef EFI_TIME;

#define EFI_TIME_ADJUST_DAYLIGHT 0x1
#define EFI_TIME_IN_DAYLIGHT     0x2

#define EFI_UNSPECIFIED_TIMEZONE 0x7FF

struct {
    UInt32 Resolution;
    UInt32 Accuracy;
    bool SetsToZero;
} typedef EFI_TIME_CAPABILITIES;
