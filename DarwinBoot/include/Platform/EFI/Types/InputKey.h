// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TYPES_INPUTKEY_H__
#define __PLATFORM_EFI_TYPES_INPUTKEY_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

struct {
    UInt16 ScanCode;
    SInt16 UnicodeChar;
} typedef EFI_INPUT_KEY;

#endif /* __PLATFORM_EFI_TYPES_INPUTKEY_H__ */
