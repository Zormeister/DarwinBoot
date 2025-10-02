// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <libcxxabi.h>
#include <panic.h>

namespace __cxxabiv1 {

void __cxa_pure_virtual()
{
    panic("__cxa_pure_virtual: Connor! The fuck are you doing?");
}

}
