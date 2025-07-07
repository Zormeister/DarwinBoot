// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_COMPONENT_NAME2_PROTOCOL_GUID \
 {0x6a7a5cff,0xe8d9,0x4f70,\
  {0xba,0xda,0x75,0xab,0x30,0x25,0xce,0x14}}

extern EFI_GUID gEfiComponentName2ProtocolGuid;

typedef struct _EFI_COMPONENT_NAME2_PROTOCOL EFI_COMPONENT_NAME2_PROTOCOL;

struct _EFI_COMPONENT_NAME2_PROTOCOL {
    EFI_STATUS (*GetDriverName)(EFI_COMPONENT_NAME2_PROTOCOL *This, const char *Language, wchar_t **DriverName);
    EFI_STATUS (*GetControllerName)(EFI_COMPONENT_NAME2_PROTOCOL *This, EFI_HANDLE ControllerHandle, 
                                    EFI_HANDLE ChildHandle, const char *Language, wchar_t **DriverName);
    const char *SupportedLanguages;
};
