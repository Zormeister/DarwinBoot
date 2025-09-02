// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libcxx_new__
#define __libcxx_new__

#include <CoreDarwinBoot/libc.h>

void *operator new(size_t size);
void *operator new[](size_t size);

void operator delete(void *p) noexcept;
void operator delete[](void *p) noexcept;

#endif