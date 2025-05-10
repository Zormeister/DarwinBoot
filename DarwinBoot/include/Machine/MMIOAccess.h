// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CDBBasicTypes.h>

/* Interfaces for MMIODevice. */
UInt32 MMIORead32(volatile UInt8 *Mem, UInt32 reg);
UInt16 MMIORead16(volatile UInt8 *Mem, UInt32 reg);
UInt8 MMIORead8(volatile UInt8 *Mem, UInt32 reg);

void MMIOWrite32(volatile UInt8 *Mem, UInt32 reg, UInt32 Value);
void MMIOWrite16(volatile UInt8 *Mem, UInt32 reg, UInt16 Value);
void MMIOWrite8(volatile UInt8 *Mem, UInt32 reg, UInt8 Value);
