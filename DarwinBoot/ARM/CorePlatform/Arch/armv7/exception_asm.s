// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

.text

.extern (ArchIRQHandler)

.globl exception_storage

exception_storage:
.balign 128

.globl ArchIRQHandlerASM

.globl exception_table



exception_table:
b . // reset
.align 7
b . // undefined instruction
b . // either supervisor call or smon call
b . // prefect abort
b . // data abort
b . // hypervisor mode entry
b ArchIRQHandlerASM // irq interrupt
b . // fiq interrupt

ArchIRQHandlerASM:
    // save all of our registers to exception_storage
    stp r0,r1 [exception_storage, #0]
    stp r2,r3 [exception_storage, #8]
    stp r4,r5 [exception_storage, #16]
    stp r6,r7 [exception_storage, #24]
    stp r8,r9 [exception_storage, #32]
    stp r10,r11 [exception_storage, #40]
    stp r12,r13 [exception_storage, #48]
    stp r14,r15 [exception_storage, #52]

    // now, jump to our IRQ handler
    b ArchIRQHandler

    // if/when we get back here, restore the state
    ldp r0,r1 [exception_storage, #0]
    ldp r2,r3 [exception_storage, #8]
    ldp r4,r5 [exception_storage, #16]
    ldp r6,r7 [exception_storage, #24]
    ldp r8,r9 [exception_storage, #32]
    ldp r10,r11 [exception_storage, #40]
    ldp r12,r13 [exception_storage, #48]
    ldp r14,r15 [exception_storage, #52]
    eret
