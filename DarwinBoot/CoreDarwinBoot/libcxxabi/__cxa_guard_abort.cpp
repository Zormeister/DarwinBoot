// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libcxxabi.h>
#include <CoreDarwinBoot/libc.h>

namespace __cxxabiv1 {

    void __cxa_guard_abort(uint64_t *guard)
    {
        //
        // do absolutely nothing.
        //
    }

}
