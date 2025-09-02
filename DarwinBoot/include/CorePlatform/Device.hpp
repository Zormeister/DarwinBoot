// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CorePlatform/IDevice.hpp>

namespace CorePlatform {

    class CDevice : public IDevice {
        public:
        CDevice(const char **ppCompatibleID, size_t numCompatibles);

        virtual bool matchesCompatible(const char *pCompatibleID) override;

        virtual DeviceType getDeviceType(void) override;
    };

}
