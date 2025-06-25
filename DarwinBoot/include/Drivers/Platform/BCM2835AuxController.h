// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.h>

/* These registers are aligned by 0x4. I'll read them as 32-bit. */

#define rAUX_IRQ 0x0
#define AUX_IRQ__UART1_PENDING_IRQ (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_MASK (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_SHIFT 0
#define AUX_IRQ__SPI1_PENDING_IRQ (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_MASK (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_SHIFT 1
#define AUX_IRQ__SPI2_PENDING_IRQ (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_MASK (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_SHIFT 2

#define rAUX_ENABLES 0x4
#define AUX_ENABLES__ENABLE_UART1 (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_MASK (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_SHIFT 0
#define AUX_ENABLES__ENABLE_SPI1 (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_MASK (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_SHIFT 1
#define AUX_ENABLES__ENABLE_SPI2 (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_MASK (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_SHIFT 2

enum {
    BCM2835AuxPeripheralUART = 1,
    BCM2835AuxPeripheralSPI1,
    BCM2835AuxPeripheralSPI2,
} typedef BCM2835AuxPeripheral;

struct {
    PlatformDriver Driver;

    void (*EnablePeripheral)(PlatformDriver *This, BCM2835AuxPeripheral Peripheral, bool Enable);

    /* TRUE == IRQ pending, FALSE == No IRQ pending. */
    bool (*IsPendingIRQ)(PlatformDriver *This, BCM2835AuxPeripheral Peripheral);

    bool (*IsPeripheralEnabled)(PlatformDriver *This, BCM2835AuxPeripheral Peripheral);

    MMIODevice *AuxDev;

    UInt32 EnabledState;
} typedef BCM2835AuxController;

#define TO_BCM2835_AUX_CONTROLLER(con) (BCM2835AuxController *)(con)

/* In-memory creation. */
BCM2835AuxController *BCM2835AuxControllerCreate(PlatformDevice *dev);

/* This will initialise any old BCM2835AuxController object, so long as you have a PlatformDevice */
bool BCM2835AuxControllerInit(PlatformDriver *controller, PlatformDevice *dev);
