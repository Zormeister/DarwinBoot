// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/IDevice.hpp>

using namespace CorePlatform;

IDevice::IDevice(const char **ppCompatibleIDs, size_t numCompatibles)
{
    fCompatibleIDs = ppCompatibleIDs;
    fNumCompatibleIDs = numCompatibles;
}