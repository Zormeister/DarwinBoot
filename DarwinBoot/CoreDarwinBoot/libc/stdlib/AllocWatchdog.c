// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/libc_compat.h>
#include "AllocWatchdog.h"
#include "stdlib_internal.h"

/*
 * God this reminds me of the old days...
 * 'Common Memory Services'...
 * I honestly do prefer DarwinBoot post-rewrite though.
 * That shit was a NIGHTMARE.
 */

AllocWatchdog gMemWDG;

/* Arbitrary value. WDG can handle itself. */
#define CAPACITY_INCREMENT 30

bool AllocWDGInit(AllocWatchdog *Wdg) {
    Wdg->Revision = 1;
    /* Avoid roping into ourself by using the stdlib internal call. */
    Wdg->Allocs = platform_malloc(sizeof(AllocWDGAlloc) * CAPACITY_INCREMENT);
    if (Wdg->Allocs == NULL) {
        /* 
         * We have failed to establish ourselves. 
         * We can either commit suicide (panic) or
         * gracefully exit.
         */
        return false;
    }
    Wdg->Allocs[0].Ptr = Wdg->Allocs; /* Track ourself. */
    Wdg->Allocs[0].Size = (sizeof(AllocWDGAlloc) * CAPACITY_INCREMENT);
    Wdg->TotalAllocs = CAPACITY_INCREMENT;
    return true;
}

static inline size_t AllocWDGFindEmptyEntry(AllocWatchdog *Wdg) {
    size_t last;

    for (size_t i = 0; i < Wdg->TotalAllocs; i++) {
        if (Wdg->Allocs[i].Ptr == NULL) {
            return i;
        }
        last = i;
    }
    /* if we haven't returned yet, this means we've genuinely ran out of space. */
    size_t size = Wdg->Allocs[0].Size + (sizeof(AllocWDGAlloc) * CAPACITY_INCREMENT);
    AllocWDGAlloc *old = Wdg->Allocs;
    Wdg->Allocs = platform_malloc(size);
    memcpy(Wdg->Allocs, old, old[0].Size);
    platform_free(old);
    Wdg->Allocs[0].Ptr = Wdg->Allocs;
    Wdg->Allocs[0].Size = size;
    Wdg->TotalAllocs += CAPACITY_INCREMENT;
    return last++;
}

bool AllocWDGAdd(AllocWatchdog *Wdg, void *Ptr, size_t Size) {
    if (Ptr == NULL) { return false; }
    size_t next = AllocWDGFindEmptyEntry(Wdg);
    Wdg->Allocs[next].Ptr = Ptr;
    Wdg->Allocs[next].Size = Size;
    return true;
};

size_t AllocWDGFindSize(AllocWatchdog *Wdg, void *Ptr) {
    for (size_t i = 0; i < Wdg->TotalAllocs; i++) {
        if (Wdg->Allocs[i].Ptr == Ptr) {
            return Wdg->Allocs[i].Size;
        }
    }

    return 0;
};

void AllocWDGRemove(AllocWatchdog *Wdg, void *Ptr) {
    if (Ptr == NULL) { return; }
    for (size_t i = 0; i < Wdg->TotalAllocs; i++) {
        if (Wdg->Allocs[i].Ptr == Ptr) {
            Wdg->Allocs[i].Ptr = NULL;
            Wdg->Allocs[i].Size = 0;
        }
    }
};

void AllocWDGReplace(AllocWatchdog *Wdg, void *Old, void *New, size_t NewSize) {
    if (Old == NULL || New == NULL) { return; }
    for (size_t i = 0; i < Wdg->TotalAllocs; i++) {
        if (Wdg->Allocs[i].Ptr == Old) {
            Wdg->Allocs[i].Ptr = New;
            Wdg->Allocs[i].Size = NewSize;
        }
    }
}

void AllocWDGShutdown(AllocWatchdog *Wdg) {
    /* This SHOULD be called prior to jumping to the kernel- call this approximately right before shutting down the platform freeing svcs */
    platform_free(Wdg->Allocs);
    Wdg->TotalAllocs = 0;
    Wdg->Revision = 0;
};
