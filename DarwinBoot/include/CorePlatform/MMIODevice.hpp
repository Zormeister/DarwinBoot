// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CorePlatform/Device.hpp>

namespace CorePlatform {

    class CMMIODevice : public CDevice {
        public:
        CMMIODevice(const char **ppCompatibleID, size_t numCompatibles, physical_address_t addr, size_t memSize);

        /* MMIO accessors */
        virtual UInt8 readReg8(UInt32 reg);
        virtual UInt16 readReg16(UInt32 reg);
        virtual UInt32 readReg32(UInt32 reg);

        virtual void writeReg8(UInt32 reg, UInt8 value);
        virtual void writeReg16(UInt32 reg, UInt16 value);
        virtual void writeReg32(UInt32 reg, UInt32 value);

        virtual DeviceType getDeviceType() override;

        protected:
        volatile UInt8 *fRegisters;
        physical_address_t fAddress;
        size_t fMemorySize;
    };
}
