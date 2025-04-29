// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/libc_compat.h>
#include "AllocWatchdog.h"

void *realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else {
        void *ret = malloc(size);
        if (ret) {
            memcpy(ret, ptr, AllocWDGFindSize(&gMemWDG, ptr));
            AllocWDGReplace(&gMemWDG, ptr, ret, size);
            free(ptr);
            return ret;
        } else {
            return NULL;
        }
    }
}