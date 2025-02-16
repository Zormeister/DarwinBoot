// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

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