// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libcxxabi.h>
#include <CoreDarwinBoot/libc.h>
#include "libcxxabi_internal.hpp"

//
// I referenced the OSDev wiki for this.
//

namespace __cxxabiv1 {

size_t _atexit_count;
struct _atexit_list_entry_t _atexit_funcs[ATEXIT_MAX_FUNCS];

int __cxa_atexit(void (*destructor)(void *), void *arg, void *dso)
{
    for (int i = 0; i < ATEXIT_MAX_FUNCS; i++) {
        if (_atexit_funcs[i].destructor == NULL) {
            _atexit_funcs[i].destructor = destructor;
            _atexit_funcs[i].object = arg;
            _atexit_funcs[i].dso = dso;
            _atexit_count++;

            return 0;
        }
    }

    return -1;
}

}
