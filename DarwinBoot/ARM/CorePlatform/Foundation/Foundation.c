// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>

/* TODO: reloc? */
char BootMessage[] = {
    "=======================================\n"
    "::\n"
    ":: %s for %s, Copyright 2024-2025 Zormeister\n"
    "::\n"
    ":: BUILD_TAG: %s\n"
    "::\n"
    ":: BUILD_STYLE: %s\n"
    "::\n"
    "=======================================\n"
};

struct CorePlatformRoot {
    UInt32 DeviceCount;
    PlatformDevice *Devices;
};

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
extern PageMapEntry *PageMap[];
AllocatedMemoryMapEntry FirstAllocation;
AllocatedMemoryMapEntry *AllocationMap[];
UInt64 NumPages;

PageMapEntry *GetPageMapEntryForAddress(uint64_t address) {
    PageMapEntry *Entry;
    int i = 0;
    while (Entry = PageMap[i], Entry != NULL) {
        if (address > Entry->PageStart && address < Entry->PageEnd) {
            return Entry;
        }
    }
    return NULL;
}

PageMapEntry *FindEmptyPage() {
    PageMapEntry *entry;
    int i = 0;
    while (entry = PageMap[i], i < NumPages, i++) {

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

}

void FreeMemory(void *mem) {

}

bool initialize_memory_allocator(MemoryConfig memcfg) {
    CurrentMemoryConfig.MemBase = memcfg.MemBase;
    CurrentMemoryConfig.MemSize = memcfg.MemSize;
    PageSize = 4096; // We aren't going to use any other page size - right?
    InitialPage.PageStart = memcfg.MemBase;
    InitialPage.PageEnd = InitialPage.PageStart + InitialPage.PageEnd;
    return true;
}

static struct CorePlatformRoot PlatformRoot;

bool AddPageRange(MemoryConfig range) {
    UInt64 base = range.MemBase;
    UInt64 size = range.MemSize;

}

bool CorePlatformInitialize(MemoryConfig memcfg, PlatformDeviceDescriptor *Devices) {
    int i = 0;
    PlatformDeviceDescriptor dev;
    if (initialize_memory_allocator(memcfg) == true) {
        while (dev = Devices[i], dev.Compatible != NULL, i++) {
            /* Need to implement Malloc n' stuff. */
        }
    }
    
    return true;
}