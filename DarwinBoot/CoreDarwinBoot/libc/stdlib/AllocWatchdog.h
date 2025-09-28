// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __STLIB_ALLOC_WATCHDOG_H__
#define __STLIB_ALLOC_WATCHDOG_H__

#include <stdio.h>

/* !!! THIS IS A PRIVATE INTERFACE USED BY LIBC !!! */

struct {
    void *Ptr;
    size_t Size;
} typedef AllocWDGAlloc;

struct {
    UInt32 Revision;

    AllocWDGAlloc *Allocs;
    size_t TotalAllocs;
} typedef AllocWatchdog;

extern AllocWatchdog gMemWDG;

bool AllocWDGInit(AllocWatchdog *Wdg);
bool AllocWDGAdd(AllocWatchdog *Wdg, void *Ptr, size_t Size);
size_t AllocWDGFindSize(AllocWatchdog *Wdg, void *Ptr);
void AllocWDGRemove(AllocWatchdog *Wdg, void *Ptr);
void AllocWDGReplace(AllocWatchdog *Wdg, void *Old, void *New, size_t NewSize);
void AllocWDGShutdown(AllocWatchdog *Wdg);

#endif /* __STLIB_ALLOC_WATCHDOG_H__ */
