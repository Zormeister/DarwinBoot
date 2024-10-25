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

enum {
    PHYS,
    VIRT,
    BUS,
};

#define UART_COUNT 1
#define SPI_COUNT 2

static inline uint32_t GET_PERPH_BASE(uint32_t kind) {
    if (kind == PHYS) {
        return PERIPHERAL_BASE;
    } else if (kind == VIRT) {
        return PERIPHERAL_VIRTUAL_BASE;
    } else if (kind == BUS) {
        return PERIPHERAL_BUS_BASE;
    }
}

#define AUX_PERPH_BASE(kind) GET_PERPH_BASE((kind)) + 0x215000

#define AUX_IRQ 0x0
