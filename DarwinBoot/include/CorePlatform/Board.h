// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

// done by SoC code
CDBPhysicalAddress CPBoardGetKernelLoadAddress(void);

#if BCM2712
    #include <Platform/SoC/BCM2712/Board.h>
#endif
