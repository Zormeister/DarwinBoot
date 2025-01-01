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

#define rAUX_IRQ 0x0
#define AUX_IRQ__UART1_PENDING_IRQ_MASK (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_SHIFT 0
#define AUX_IRQ__SPI1_PENDING_IRQ_MASK (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_SHIFT 1
#define AUX_IRQ__SPI2_PENDING_IRQ_MASK (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_SHIFT 2

#define rAUX_ENABLES 0x4
#define AUX_ENABLES__ENABLE_UART1_MASK (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_SHIFT 0
#define AUX_ENABLES__ENABLE_SPI1_MASK (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_SHIFT 1
#define AUX_ENABLES__ENABLE_SPI2_MASK (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_SHIFT 2