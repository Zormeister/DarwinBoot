/* Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License. */

ENTRY(_start)

SECTIONS
{
    . = 0x40010000; /* Load address needs to be higher than the DT memory range. */
    .text : { *(.text) }
    .data : { *(.data) }
    .bss :  { *(.bss)  *(COMMON) }
}
