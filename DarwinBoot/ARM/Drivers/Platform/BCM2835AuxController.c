// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Drivers/Platform/BCM2835AuxController.h>

static bool IsPeripheralEnabled(PlatformDriver *Driver, BCM2835AuxPeripheral Peripheral)
{
    BCM2835AuxController *Controller = TO_BCM2835_AUX_CONTROLLER(Driver);
    switch (Peripheral) {
        case BCM2835AuxPeripheralUART:
            return !!(Controller->EnabledState & AUX_ENABLES__ENABLE_UART1);
        case BCM2835AuxPeripheralSPI1:
            return !!(Controller->EnabledState & AUX_ENABLES__ENABLE_SPI1);
        case BCM2835AuxPeripheralSPI2:
            return !!(Controller->EnabledState & AUX_ENABLES__ENABLE_SPI2);
    }
}

static void EnablePeripheral(PlatformDriver *Driver, BCM2835AuxPeripheral Peripheral, bool enable)
{
    BCM2835AuxController *Controller = TO_BCM2835_AUX_CONTROLLER(Driver);
    switch (Peripheral) {
        case BCM2835AuxPeripheralUART: {
            if ((Controller->EnabledState & AUX_ENABLES__ENABLE_UART1) && enable) {
                return;
            } else {
                if (enable) {
                    Controller->EnabledState |= AUX_ENABLES__ENABLE_UART1;
                } else {
                    Controller->EnabledState &= ~(AUX_ENABLES__ENABLE_UART1);
                }
                Controller->AuxDev->WriteReg32(TO_PLATFORM_DEVICE(Controller->AuxDev), rAUX_ENABLES, Controller->EnabledState);
                return;
            }
        }
        case BCM2835AuxPeripheralSPI1: {
            if ((Controller->EnabledState & AUX_ENABLES__ENABLE_SPI1) && enable) {
                return;
            } else {
                if (enable) {
                    Controller->EnabledState |= AUX_ENABLES__ENABLE_SPI1;
                } else {
                    Controller->EnabledState &= ~(AUX_ENABLES__ENABLE_SPI1);
                }
                Controller->AuxDev->WriteReg32(TO_PLATFORM_DEVICE(Controller->AuxDev), rAUX_ENABLES, Controller->EnabledState);
                return;
            }
        }
        case BCM2835AuxPeripheralSPI2: {
            if ((Controller->EnabledState & AUX_ENABLES__ENABLE_SPI2) && enable) {
                return;
            } else {
                if (enable) {
                    Controller->EnabledState |= AUX_ENABLES__ENABLE_SPI2;
                } else {
                    Controller->EnabledState &= ~(AUX_ENABLES__ENABLE_SPI2);
                }
                Controller->AuxDev->WriteReg32(TO_PLATFORM_DEVICE(Controller->AuxDev), rAUX_ENABLES, Controller->EnabledState);
                return;
            }
        }
    }
}

static bool IsPendingIRQ(PlatformDriver *Driver, BCM2835AuxPeripheral Peripheral)
{
    BCM2835AuxController *Controller = TO_BCM2835_AUX_CONTROLLER(Driver);
    UInt32 irq = Controller->AuxDev->ReadReg32(TO_PLATFORM_DEVICE(Controller->AuxDev), rAUX_IRQ);
    switch (Peripheral) {
        case BCM2835AuxPeripheralUART:
            return (irq & AUX_IRQ__UART1_PENDING_IRQ);
        case BCM2835AuxPeripheralSPI1:
            return (irq & AUX_IRQ__SPI1_PENDING_IRQ);
        case BCM2835AuxPeripheralSPI2:
            return (irq & AUX_IRQ__SPI2_PENDING_IRQ);
    }
}

/* Exported */
bool BCM2835AuxControllerInit(PlatformDriver *Driver, PlatformDevice *dev)
{
    BCM2835AuxController *Controller = TO_BCM2835_AUX_CONTROLLER(Driver);

    Controller->AuxDev = TO_MMIO_DEVICE(dev);

    /* I don't think the Aux device can manually toggle itself, and since we have no other clients I doubt anyone else would write to rAUX_ENABLES. */
    Controller->EnabledState = Controller->AuxDev->ReadReg32(TO_PLATFORM_DEVICE(Controller->AuxDev), rAUX_ENABLES);

    /* Populate callbacks. */
    Controller->IsPeripheralEnabled = &IsPeripheralEnabled;
    Controller->EnablePeripheral = &EnablePeripheral;
    Controller->IsPendingIRQ = &IsPendingIRQ;

    Controller->Driver.DriverName = "BCM2835AuxController"; /* there should only ever be one of us. */
    Controller->Driver.Class = 0;
    Controller->Driver.SubClass = 0;
    return true;
}
