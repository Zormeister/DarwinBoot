// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Foundation.h>

typedef void (*IRQHandler)(void);

enum {
    SWIRQ,
    HWIRQ,
    FIQ
} typedef IRQType;

struct {
    UInt32 SourceID;
    const char *Name;
} typedef IRQSourceTableEntry;

struct {
    UInt32 MaxIRQs;
    UInt32 Flags;
    IRQSourceTableEntry *FIQTable;
    IRQSourceTableEntry *SWIRQTable;
    IRQSourceTableEntry *HWIRQTable;
} typedef IRQTable;

struct {

} typedef IRQMgr;

IRQMgr *IRQMgrCreate(IRQTable *Tbl);

void IRQRegisterForIRQ(IRQMgr *Mgr, UInt32 irqnum, IRQHandler handler);

