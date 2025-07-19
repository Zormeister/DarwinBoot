// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "MemoryMap.h"
#include <CoreDarwinBoot/CDBBasicTypes.h>

#define NUM_UART 1
#define NUM_SPI  2

#define GPIO_BASE PERIPHERAL_MMIO_BASE + 0x200000

#define UART0_BASE PERIPHERAL_MMIO_BASE + 0x201000

#define UART_DR 0x00