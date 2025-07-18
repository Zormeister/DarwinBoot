// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "Drivers/Driver.h"
#include <CorePlatform/Foundation.h>
#include <Drivers/Platform/BCM2835AuxController.h>
#include <Drivers/Serial.h>

struct {
    SerialDriver Base;

    BCM2835AuxController *AuxCon; /* we need this */
} typedef BCM2835AuxUART;

/*
 * The REAL baudrate of the UART1 is as follows:
 * - rate = SysClkFreq / 8 * (rUART1_BAUDRATE + 1)
 *
 * The base system clock after a system reset IS 250 MHz.
 */

bool BCM2835AuxUARTInit(BCM2835AuxUART *Driver, MMIODevice *UARTDevice, BCM2835AuxController *AuxCon);

/* MMIO Registers, doc ref: BCM2711 I/O Peripherals. */
#define rUART1_IO      0x0
#define UART1_IO__MASK 0xFF

#define rUART1_IRQ_ENABLE                     0x4
#define UART1_IRQ_ENABLE__ENABLE_TX_IRQ       (1 << 0)
#define UART1_IRQ_ENABLE__ENABLE_TX_IRQ_SHIFT 0
#define UART1_IRQ_ENABLE__ENABLE_RX_IRQ       (1 << 1)
#define UART1_IRQ_ENABLE__ENABLE_RX_IRQ_SHIFT 1
#define UART1_IRQ_ENABLE__16BR_MASK           0xFF

#define rUART1_IRQ_IDENTIFY                        0x8
#define UART1_IRQ_IDENTIFY__IRQ_PENDING            (1 << 0)
#define UART1_IRQ_IDENTIFY__IRQ_PENDING_SHIFT      0
#define UART1_IRQ_IDENTIFY__IRQ_ID_FIFO_CLEAR_BITS (1 << 1 | 1 << 2)

#define rUART1_LINE_CNTL                   0xC
#define UART1_LINE_CNTL__DATA_SIZE         (1 << 0)
#define UART1_LINE_CNTL__DATA_SIZE_SHIFT   0
#define UART1_LINE_CNTL__BREAK             (1 << 6)
#define UART1_LINE_CNTL__BREAK_SHIFT       6
#define UART1_LINE_CNTL__DLAB_ACCESS       (1 << 7)
#define UART1_LINE_CNTL__DLAB_ACCESS_SHIFT 7

#define rUART1_MODEM_CNTL           0x10
#define UART1_MODEM_CNTL__RTS       (1 << 0)
#define UART1_MODEL_CNTL__RTS_SHIFT 0

#define rUART1_LINE_STATUS                  0x14
#define UART1_LINE_STATUS__DATA_READY       (1 << 0)
#define UART1_LINE_STATUS__DATA_READY_SHIFT 0
#define UART1_LINE_STATUS__RX_OVERRUN       (1 << 1)
#define UART1_LINE_STATUS__RX_OVERRUN_SHIFT 1
#define UART1_LINE_STATUS__TX_EMPTY         (1 << 5)
#define UART1_LINE_STATUS__TX_EMPTY_SHIFT   5
#define UART1_LINE_STATUS__TX_IDLE          (1 << 6)
#define UART1_LINE_STATUS__TX_IDLE_SHIFT    6

#define rUART1_MODEM_STATUS                  0x18
#define UART1_MODEM_STATUS__CTS_STATUS       (1 << 4)
#define UART1_MODEM_STATUS__CTS_STATUS_SHIFT 4

#define rUART1_SCRATCH              0x1C
#define UART1_SCRATCH__SCRATCH_MASK 0xFF

#define rUART1_CNTL                               0x20
#define UART1_CNTL__RX_ENABLE                     (1 << 0)
#define UART1_CNTL__RX_ENABLE_SHIFT               0
#define UART1_CNTL__TX_ENABLE                     (1 << 1)
#define UART1_CNTL__TX_ENABLE_SHIFT               1
#define UART1_CNTL__RX_RTS_AUTO_FLOW_ENABLE       (1 << 2)
#define UART1_CNTL__RX_RTS_AUTO_FLOW_ENABLE_SHIFT 2
#define UART1_CNTL__TX_CTS_AUTO_FLOW_ENABLE       (1 << 3)
#define UART1_CNTL__TX_CTS_AUTO_FLOW_ENABLE_SHIFT 3
#define UART1_CNTL__RTS_AUTO_FLOW_LEVEL_MASK      (1 << 4) | (1 << 5)
#define UART1_CNTL__RTS_AUTO_FLOW_LEVEL_SHIFT     4
#define UART1_CNTL__RTS_ASSERT_LEVEL              (1 << 6)
#define UART1_CNTL__RTS_ASSERT_LEVEL_SHIFT        6
#define UART1_CNTL__CTS_ASSERT_LEVEL              (1 << 7)
#define UART1_CNTL__CTS_ASSERT_LEVEL_SHIFT        7

enum {
    RTS_AUTO_FLOW_LEVEL_3SPACES = 0, /* 00 */
    RTS_AUTO_FLOW_LEVEL_2SPACES = 1, /* 01 */
    RTS_AUTO_FLOW_LEVEL_1SPACE = 2,  /* 10 */
    RTS_AUTO_FLOW_LEVEL_4SPACES = 3  /* 11 */
};

#define rUART1_STATUS                          0x24
#define UART1_STATUS__SYMBOL_AVAILABLE         (1 << 0)
#define UART1_STATUS__SYMBOL_AVAILABLE_SHIFT   0
#define UART1_STATUS__SPACE_AVAILABLE          (1 << 1)
#define UART1_STATUS__SPACE_AVAILABLE_SHIFT    1
#define UART1_STATUS__RX_IDLE                  (1 << 2)
#define UART1_STATUS__RX_IDLE_SHIFT            2
#define UART1_STATUS__TX_IDLE                  (1 << 3)
#define UART1_STATUS__TX_IDLE_SHIFT            3
#define UART1_STATUS__RX_OVERRUN               (1 << 4)
#define UART1_STATUS__RX_OVERRUN_SHIFT         4
#define UART1_STATUS__TX_FULL                  (1 << 5)
#define UART1_STATUS__TX_FULL_SHIFT            5
#define UART1_STATUS__RTS_STATUS               (1 << 6)
#define UART1_STATUS__RTS_STATUS_SHIFT         6
#define UART1_STATUS__CTS_STATUS               (1 << 7)
#define UART1_STATUS__CTS_STATUS_SHIFT         7
#define UART1_STATUS__TX_FIFO_EMPTY            (1 << 8)
#define UART1_STATUS__TX_FIFO_EMPTY_SHIFT      8
#define UART1_STATUS__TX_DONE                  (1 << 9)
#define UART1_STATUS__TX_DONE_SHIFT            9
#define UART1_STATUS__RX_FIFO_FILL_LEVEL       (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19)
#define UART1_STATUS__RX_FIFO_FILL_LEVEL_SHIFT 16
#define UART1_STATUS__TX_FIFO_FILL_LEVEL       (1 << 24) | (1 << 25) | (1 << 26) | (1 << 27)
#define UART1_STATUS__TX_FIFO_FILL_LEVEL_SHIFT 27

#define rUART1_BAUDRATE                 0x28
#define UART1_BAUDRATE__BAUD_RATE       0xFFFF /* deadass using a constant for this one. */
#define UART1_BAUDRATE__BAUD_RATE_SHIFT 0
