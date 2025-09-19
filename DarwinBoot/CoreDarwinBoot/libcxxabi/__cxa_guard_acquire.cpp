// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libcxxabi.h>
#include <CoreDarwinBoot/libc.h>

namespace __cxxabiv1 {

    //
    // honest to god do i have locks in a BOOTLOADER?
    //
    int __cxa_guard_acquire(uint64_t *guard)
    {
        return 1;
    }

}
