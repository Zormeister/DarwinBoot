// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

namespace CorePlatform {

    enum struct DeviceType {
        Generic,
        MMIO,
    };

    class IDevice {
        public:
        IDevice(const char **ppCompatibleID, size_t numCompatibles);

        public:
        virtual bool matchesCompatible(const char *pCompatibleID) = 0;

        virtual DeviceType getDeviceType(void) = 0;

        protected:
        const char **fCompatibleIDs;
        size_t fNumCompatibleIDs;
    };

}