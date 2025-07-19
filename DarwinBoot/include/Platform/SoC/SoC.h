// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

#if __ARM_16K_PAGES__
    #define PAGE_SIZE 16384
#else
    #define PAGE_SIZE 4096
#endif

#if BCM2712
    #include <Platform/SoC/BCM2712/Board.h>
#endif
