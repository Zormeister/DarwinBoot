// Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

#include <CorePlatform/Foundation.h>

typedef void (*IRQHandler)(void);

enum {
    SWIRQ,
    HWIRQ,
    FIQ
} typedef IRQType;

struct IRQSourceTableEntry {
    UInt32 SourceID;
    const char *Name;
};

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

