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
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include "MemoryMap.h"

#define NUM_UART 5
#define NUM_SPI 6

#define GPIO_BASE PERIPHERAL_MMIO_BASE + 0x200000

#define AUX_BASE PERIPHERAL_MMIO_BASE + 0x215000

#define SYS_TIMER_BASE PERIPHERAL_MMIO_BASE + 0x3000

#define ARM_TIMER_BASE PERIPHERAL_MMIO_BASE + 0xB000

#define MAILBOX_BASE PERIPHERAL_MMIO_BASE + 0xB880

#define DMA_BASE(n) PERIPHERAL_MMIO_BASE + 0x7000 + (n * 0x100)

#define UART_BASE(n) PERIPHERAL_MMIO_BASE + 0x201000 + (n * 0x200)

#define UART0_BASE UART_BASE(0)
#define UART2_BASE UART_BASE(2)
#define UART3_BASE UART_BASE(3)
#define UART4_BASE UART_BASE(4)
#define UART5_BASE UART_BASE(5)

#define DMA0_BASE DMA_BASE(0)
#define DMA1_BASE DMA_BASE(1)
#define DMA2_BASE DMA_BASE(2)
#define DMA3_BASE DMA_BASE(3)
#define DMA4_BASE DMA_BASE(4)
#define DMA5_BASE DMA_BASE(5)
#define DMA6_BASE DMA_BASE(6)
#define DMA7_BASE DMA_BASE(7)
#define DMA8_BASE DMA_BASE(8)
#define DMA9_BASE DMA_BASE(9)
#define DMA10_BASE DMA_BASE(10)
#define DMA11_BASE DMA_BASE(11)
#define DMA12_BASE DMA_BASE(12)
#define DMA13_BASE DMA_BASE(13)
#define DMA14_BASE DMA_BASE(14)
#define DMA15_BASE PERIPHERAL_MMIO_BASE + 0xE05000