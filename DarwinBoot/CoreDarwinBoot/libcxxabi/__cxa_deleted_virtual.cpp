// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libcxxabi.h>
#include <CoreDarwinBoot/libc.h>

namespace __cxxabiv1 {

void __cxa_deleted_virtual()
{
    // "This routine shall not return and while this ABI does not otherwise specify its behavior,
    //  it is expected that it will terminate the program, possibly with an error message."
    panic("__cxa_deleted_virtual: called a deleted virtual function!!!\n");
}

}
