// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

/* ARM exception levels! */

enum {
    EL0 = 0,
    EL1 = 1,
    EL2 = 2,
    EL3 = 3
} typedef ARMExceptionLevel;

ARMExceptionLevel ArchGetExceptionLevel();

extern ARMExceptionLevel gCurrentExceptionLevel;
