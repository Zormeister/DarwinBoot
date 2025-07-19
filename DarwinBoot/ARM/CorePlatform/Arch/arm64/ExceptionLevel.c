// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Arch/ExceptionLevel.h>

static bool read_el = false;

ARMExceptionLevel gCurrentExceptionLevel = Unsupported;

ARMExceptionLevel ArchGetExceptionLevel()
{
    if (!read_el) {
        uint32_t tmp = __builtin_arm_rsr("CurrentEL");
    }

    return gCurrentExceptionLevel;
}
