// Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

.section ".boot"

.global _entry

.extern (_gProvidedFDT)
.extern (_panic_halt)

// ref: https://wiki.osdev.org/Raspberry_Pi_Bare_Bones#Pi_3,_4

// TODO: everything
// I need to store the DTB pointer and then jump to the C foundation.
// AKA: start_64.c @ start

_entry:
   // Setup stack.
   LDR      x5, = _entry
   MOV      sp, x5

   LDR      x5, = __bss_start
   LDR      w6 = __bss_size

1: CBZ      w6, _panic_halt
   STR      xzr, [x5], #8
   SUB	    w6, w6, #1
   CBNZ     w6, _panic_halt

   // Store FDT pointer
   LDR _gProvidedFDT, [x0]
   // X1 through X3 get unused, though could potentially get used later
   // Ignore them for now I guess.

2: BL _platform_init