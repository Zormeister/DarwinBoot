// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Machine/MMIOAccess.h>

/* if there's any special requirements, they should be here under macro definitions */

UInt32 MMIORead32(volatile UInt8 *Mem, UInt32 Offset) {
    return *(volatile UInt32 *)(Mem + Offset);
}

UInt16 MMIORead16(volatile UInt8 *Mem, UInt32 Offset) {
    return *(volatile UInt16 *)(Mem + Offset);
}

UInt8 MMIORead8(volatile UInt8 *Mem, UInt32 Offset) {
    return *(volatile UInt8 *)(Mem + Offset);
};

void MMIOWrite32(volatile UInt8 *Mem, UInt32 Offset, UInt32 Value) {
    *(volatile UInt32 *)(Mem + Offset) = Value;
};

void MMIOWrite16(volatile UInt8 *Mem, UInt32 Offset, UInt16 Value) {
    *(volatile UInt16 *)(Mem + Offset) = Value;
};

void MMIOWrite8(volatile UInt8 *Mem, UInt32 Offset, UInt8 Value) {
    *(volatile UInt8 *)(Mem + Offset) = Value;
};
