// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CorePlatform/Device.hpp>
#include <string.h>

using namespace CorePlatform;

CDevice::CDevice(const char **ppCompatibleID, size_t numCompatibles) : IDevice(ppCompatibleID, numCompatibles)
{
    /* Nothing else to do that isn't handled in IDevice::IDevice */
}

bool CDevice::matchesCompatible(const char *pCompatibleID)
{
    for (int i = 0; i < fNumCompatibleIDs; i++) {
        if (strncmp(fCompatibleIDs[i], pCompatibleID, strlen(pCompatibleID)) == 0) {
            return true;
        }
    }

    return false;
}