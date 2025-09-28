// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <libcxxabi.h>
#include "libcxxabi_internal.hpp"

namespace __cxxabiv1 {

    void __cxa_guard_release(uint64_t *guard) 
    {
        *(char *)guard = 1;
    }    

}
