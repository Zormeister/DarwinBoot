// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <libcxxabi.h>
#include <stdio.h>
#include "libcxxabi_internal.hpp"

//
// NOTES: in terms of bootloader deinit, this should be called right before jumping to XNU.
//
namespace __cxxabiv1 {

void __cxa_finalize(void *f) {
    if (f == NULL) {
        for (int i = _atexit_count; i >= 0; i--) {
            printf("__cxa_finalize: calling deconstructor %d", i);
            _atexit_funcs[i].destructor(_atexit_funcs[i].object);
        }
    } else {
        for (int i = _atexit_count; i >= 0; i--) {
            printf("__cxa_finalize: calling deconstructor %d", i);

            if (_atexit_funcs[i].destructor == f) {
                _atexit_funcs[i].destructor(_atexit_funcs[i].object);
                
                int shuffle = _atexit_count - i;
                
                if (shuffle) {
                    for (int j = shuffle; j <= _atexit_count; j++) {
                        _atexit_funcs[j].destructor = _atexit_funcs[j+1].destructor;
                        _atexit_funcs[j].object = _atexit_funcs[j+1].object;
                        _atexit_funcs[j].dso = _atexit_funcs[j+1].dso;
                    }

                    _atexit_count--;
                }
            }
        }
    }
}

}
