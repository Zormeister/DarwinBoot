// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

#define TIMER0_BASE 0x13000000
#define TIMER1_BASE 0x13000100
#define TIMER2_BASE 0x13000200

#define PIC_BASE    0x14000000

/* PL011s */
#define UART0_BASE  0x16000000
#define UART1_BASE  0x17000000

/* KMI - PL050. */
#define KB_BASE     0x18000000
#define MOUSE_BASE  0x19000000

#define LED_BASE    0x1A000000

/* PL181 */
#define MMCI_BASE   0x1C000000

/* PL041 */
#define AACI_BASE   0x1D000000

#define TSCI_BASE   0x1E000000

/* PL110 */
#define LCD_BASE    0xC0000000

#define SMSC_BASE   0xC8000000

#define GPIO_BASE   0xC9000000

#define SIC_BASE    0xCA000000
