// Copyright © 2024 Zormeister. All rights reserved.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

/* Technically a piece of the Aux component, divide them anyways */
#define UART1_BASE AUX_BASE + 0x40

#define rUART1_IO 0x0
#define UART1_IO__MASK 0xFF

#define rUART1_IRQ_ENABLE 0x4
#define UART1_IRQ_ENABLE__ENABLE_TX_IRQ_MASK (1 << 0)
#define UART1_IRQ_ENABLE__ENABLE_TX_IRQ_SHIFT 0
#define UART1_IRQ_ENABLE__ENABLE_RX_IRQ_MASK (1 << 1)
#define UART1_IRQ_ENABLE__ENABLE_RX_IRQ_SHIFT 1
#define UART1_IRQ_ENABLE__16BR_MASK 0xFF

#define rUART1_IRQ_IDENTIFY 0x8
#define UART1_IRQ_IDENTIFY__IRQ_PENDING_MASK (1 << 0)
#define UART1_IRQ_IDENTIFY__IRQ_PENDING_SHIFT 0
#define UART1_IRQ_IDENTIFY__IRQ_ID_FIFO_CLEAR_BITS_MASK (1 << 1 | 1 << 2)

#define rUART1_LINE_CNTL 0xC
#define UART1_LINE_CNTL__DATA_SIZE_MASK (1 << 0)
#define UART1_LINE_CNTL__DATA_SIZE_SHIFT 0
#define UART1_LINE_CNTL__BREAK_MASK (1 << 6)
#define UART1_LINE_CNTL__BREAK_SHIFT 6
#define UART1_LINE_CNTL__DLAB_ACCESS_MASK (1 << 7)
#define UART1_LINE_CNTL__DLAB_ACCESS_SHIFT 7

#define rUART1_MODEM_CNTL 0x10
#define UART1_MODEM_CNTL__RTS_MASK (1 << 0)
#define UART1_MODEL_CNTL__RTS_SHIFT 0

#define rUART1_LINE_STATUS 0x14
#define UART1_LINE_STATUS__DATA_READY_MASK (1 << 0)
#define UART1_LINE_STATUS__DATA_READY_SHIFT 0
#define UART1_LINE_STATUS__RX_OVERRUN_MASK (1 << 1)
#define UART1_LINE_STATUS__RX_OVERRUN_SHIFT 1
#define UART1_LINE_STATUS__TX_EMPTY_MASK (1 << 5)
#define UART1_LINE_STATUS__TX_EMPTY_SHIFT 5
#define UART1_LINE_STATUS__TX_IDLE_MASK (1 << 6)
#define UART1_LINE_STATUS__TX_IDLE_SHIFT 6

#define rUART1_MODEM_STATUS 0x18
#define UART1_MODEM_STATUS__CTS_STATUS_MASK (1 << 4)
#define UART1_MODEM_STATUS__CTS_STATUS_SHIFT 4

#define rUART1_SCRATCH 0x1C
#define UART1_SCRATCH__SCRATCH_MASK 0xFF

#define rUART1_CNTL 0x20
#define UART1_CNTL__RX_ENABLE_MASK (1 << 0)
#define UART1_CNTL__RX_ENABLE_SHIFT 0

#define rUART1_STATUS 0x24

#define rUART1_BAUDRATE 0x28
