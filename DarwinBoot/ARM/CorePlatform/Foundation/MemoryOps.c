// Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

#include <CorePlatform/Foundation.h>

static MemoryConfig CurrentMemoryConfig;
static UInt32 PageSize;

struct {
    void *Memory;
    UInt32 Size;
    UInt32 PageIdx;
} typedef AllocatedMemoryMapEntry;

void ClearMemory(void * ptr, UInt64 size) {
    UInt8 * uptr = ptr;
    for (UInt64 i = 0; i < size; i++) {
        uptr[i] = 0;
    }
}

PageMapEntry InitialPage;
extern PageMapEntry PageMap[];
AllocatedMemoryMapEntry FirstAllocation;
AllocatedMemoryMapEntry *AllocationMap[];
extern UInt64 MaxNumPages;

PageMapEntry *GetPageMapEntryForAddress(uint64_t address) {
    PageMapEntry Entry;
    int i = 0;
    while (Entry = PageMap[i], i < MaxNumPages) {
        if (address > Entry.PageStart && address < Entry.PageEnd) {
            return &Entry;
        }
    }
    return NULL;
}

PageMapEntry *FindEmptyPage() {
    PageMapEntry entry;
    int i = 0;
    while (entry = PageMap[i], i < MaxNumPages, i++) {
        if (entry.AvailableSpace == 4096) {
            return &entry;
        }
    } 
}

void * AllocateMemory(UInt64 size) {
    UInt32 PagesRequired;
    UInt64 LastChunkSize = 0;
    void * out = NULL;
    if (size < PageSize) {
        /* We don't need to work around any individual bits here, so just allocate after setting the needed page count. */
        PagesRequired = 1;
        goto alloc;
    } else {
        UInt64 tmp = size;
        while (tmp >= PageSize) {
            PagesRequired++;
            tmp -= PageSize;
        }
    }

    alloc:
    for (int i = 0; i < PagesRequired; i++) {
        PageMapEntry *entry = FindEmptyPage();
        if (PagesRequired == 1) {
            entry->AvailableSpace -= size;

        }
    }
}

void FreeMemory(void *mem) {

}

/* our favouries */

void *malloc(uint64_t size) {
    return AllocateMemory(size);
}