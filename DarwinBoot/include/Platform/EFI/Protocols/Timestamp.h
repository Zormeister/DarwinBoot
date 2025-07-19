// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/EFI/Types.h>

#define EFI_TIMESTAMP_PROTOCOL_GUID \
    { 0xafbfde41, 0x2e6e, 0x4262,   \
        { 0xba, 0x65, 0x62, 0xb9, 0x23, 0x6e, 0x54, 0x95 } }

extern EFI_GUID gEfiTimestampProtocolGuid;

struct {
    UInt64 Frequency;
    UInt64 EndValue;
} typedef EFI_TIMESTAMP_PROPERTIES;

typedef struct _EFI_TIMESTAMP_PROTOCOL EFI_TIMESTAMP_PROTOCOL;

struct _EFI_TIMESTAMP_PROTOCOL {
    UInt64 (*GetTimestamp)(void);
    EFI_STATUS (*GetProperties)(EFI_TIMESTAMP_PROPERTIES *Properties);
};
