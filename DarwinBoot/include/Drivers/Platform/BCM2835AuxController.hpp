// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Drivers/Driver.hpp>
#include <CorePlatform/MMIODevice.hpp>

/* These registers are aligned by 0x4. I'll read them as 32-bit. */

#define rAUX_IRQ                         0x0
#define AUX_IRQ__UART1_PENDING_IRQ       (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_MASK  (1 << 0)
#define AUX_IRQ__UART1_PENDING_IRQ_SHIFT 0
#define AUX_IRQ__SPI1_PENDING_IRQ        (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_MASK   (1 << 1)
#define AUX_IRQ__SPI1_PENDING_IRQ_SHIFT  1
#define AUX_IRQ__SPI2_PENDING_IRQ        (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_MASK   (1 << 2)
#define AUX_IRQ__SPI2_PENDING_IRQ_SHIFT  2

#define rAUX_ENABLES                    0x4
#define AUX_ENABLES__ENABLE_UART1       (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_MASK  (1 << 0)
#define AUX_ENABLES__ENABLE_UART1_SHIFT 0
#define AUX_ENABLES__ENABLE_SPI1        (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_MASK   (1 << 1)
#define AUX_ENABLES__ENABLE_SPI1_SHIFT  1
#define AUX_ENABLES__ENABLE_SPI2        (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_MASK   (1 << 2)
#define AUX_ENABLES__ENABLE_SPI2_SHIFT  2

namespace CorePlatform {

namespace Drivers {

namespace BCM2835 {

    class AuxController : public IDriver {
    public:
        AuxController(CMMIODevice *pDevice);

        enum struct Peripheral {
            UART,
            SPI1,
            SPI2,
        };

        bool isPendingIRQ(Peripheral peripheral);

        bool isPeripheralEnabled(Peripheral peripheral);

        void controlPeripheral(Peripheral peripheral, bool state);

        virtual const char *getDriverName(void) override;

        private:
        CMMIODevice *fMMIODevice;
        UInt32 fCurrentState;
    };

}

}

}
