// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __LIBCXXABI_INTERNAL__
#define __LIBCXXABI_INTERNAL__

#include <libcxxabi.h>

namespace __cxxabiv1 {

struct _atexit_list_entry_t {
    void (*destructor)(void *);
    void *object;
    void *dso;
};

#define ATEXIT_MAX_FUNCS 128

LIBCXXABI_EXTERN size_t _atexit_count;
LIBCXXABI_EXTERN struct _atexit_list_entry_t _atexit_funcs[ATEXIT_MAX_FUNCS];

}

#endif



