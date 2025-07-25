// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

.section ".boot"

.global _entry

.extern (gProvidedFDT)
.extern (halt)
.extern (platform_init)

// ref: https://wiki.osdev.org/Raspberry_Pi_Bare_Bones#Pi_3,_4

// TODO: everything
// I need to store the DTB pointer and then jump to the C foundation.
// AKA: start.c @ start

_entry:
   // Setup stack.
   LDR      x5, = _entry
   MOV      sp, x5

   LDR      x5, = __bss_start
   LDR      w6 = __bss_size

1: CBZ      w6, halt
   STR      xzr, [x5], #8
   SUB	   w6, w6, #1
   CBNZ     w6, halt

   // Store FDT pointer
   LDR gProvidedFDT, [x0]
   // X1 through X3 get unused, though could potentially get used later
   // Ignore them for now I guess.

2: BL platform_init