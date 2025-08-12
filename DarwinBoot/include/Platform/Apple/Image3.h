// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#if __has_include(<image3/image3.h>)
#define USE_LIBIMAGE3 1
#else
#define USE_LIBIMAGE3 0
#endif

#if USE_LIBIMAGE3
#include <image3/image3.h>
#endif

