// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Drivers/Platform/BCM2835AuxController.hpp>

using namespace CorePlatform::Drivers;

BCM2835::AuxController::AuxController(CorePlatform::CMMIODevice *pMMIODevice)
{
    fMMIODevice = pMMIODevice;
    fCurrentState = fMMIODevice->readReg32(rAUX_ENABLES);
}

bool BCM2835::AuxController::isPeripheralEnabled(Peripheral perph)
{
    switch (perph) {
        case Peripheral::UART:
            return !!(fCurrentState & AUX_ENABLES__ENABLE_UART1);
        case Peripheral::SPI1:
            return !!(fCurrentState & AUX_ENABLES__ENABLE_SPI1);
        case Peripheral::SPI2:
            return !!(fCurrentState & AUX_ENABLES__ENABLE_SPI2);
    }
}

const char *BCM2835::AuxController::getDriverName()
{
    return "BCM2835 Aux Controller";
}