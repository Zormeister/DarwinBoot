// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <libcxxabi.h>
#include <stdio.h>

namespace __cxxabiv1 {

void __cxa_pure_virtual()
{
    //
    // Should I enable ths on RELEASE builds?
    //
#if DEBUG || DEVELOPMENT
    printf("__cxa_pure_virtual: you have called a pure virtual function.\n");
#endif
}

}
