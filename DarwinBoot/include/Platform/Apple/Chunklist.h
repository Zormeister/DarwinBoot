// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#if __has_include(<chunklist/chunklist.h>)
#define USE_LIBCHUNKLIST 1
#else
#define USE_LIBCHUNKLIST 0
#endif

#if USE_LIBCHUNKLIST
#include <chunklist/chunklist.h>
#endif
