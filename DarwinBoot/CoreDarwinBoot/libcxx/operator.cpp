// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc.h>
#include <libcxx/headers/new.hpp>

//
// NOTE: AllocWatchdog in the libc component already keeps track of memory for us.
//

void *operator new(size_t size)
{
    return malloc(size);
}

void *operator new[](size_t size)
{
    return malloc(size);
}

void operator delete(void *p) noexcept
{
    free(p);
}

void operator delete[](void *p) noexcept
{
    free(p);
}
