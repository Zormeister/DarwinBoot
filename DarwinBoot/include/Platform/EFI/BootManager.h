// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/* uint32_t per entry -- TODO: iterate in JumpStart, set variable in RuntimeConfig that says 'hi hello we have THIS many entries.' */

#define BOOT_ORDER_VAR WSTRING("BootOrder")
