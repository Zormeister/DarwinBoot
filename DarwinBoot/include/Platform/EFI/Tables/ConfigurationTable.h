// Copyright (C) 2024-2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_EFI_TABLES_CONFIGURATIONTABLE_H__
#define __PLATFORM_EFI_TABLES_CONFIGURATIONTABLE_H__

#include <Platform/EFI/Types.h>

typedef struct _EFI_CONFIGURATION_TABLE EFI_CONFIGURATION_TABLE;

struct _EFI_CONFIGURATION_TABLE {
    EFI_GUID VendorGuid;
    void *VendorTable;
};

#endif /* __PLATFORM_EFI_TABLES_CONFIGURATIONTABLE_H__ */
