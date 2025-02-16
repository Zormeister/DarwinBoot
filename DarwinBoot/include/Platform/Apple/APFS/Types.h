// Copyright (C) 2025, Zormeister, All rights reserved. Licensed under the BSD 3-Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

typedef int64_t paddr_t;

struct prange {
    paddr_t pr_start_paddr; // First block address.
    uint64_t pr_block_count; // Number of blocks.
} typedef prange_t;

typedef unsigned char uuid_t[16];

