// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Platform/EFI/Protocols/ComponentName.h>

EFI_STATUS CoreCryptoGetDriverName(EFI_COMPONENT_NAME2_PROTOCOL *This, const char *Language, wchar_t **DriverName) {
    if (Language == NULL || DriverName == NULL) {
        return EFI_INVALID_PARAMETER;
    }
    *DriverName = WSTRING("CoreCrypto - UEFI Driver");
    return EFI_SUCCESS;
}

EFI_STATUS CoreCryptoGetControllerName(EFI_COMPONENT_NAME2_PROTOCOL *This, EFI_HANDLE ControllerHandle, 
                                    EFI_HANDLE ChildHandle, const char *Language, wchar_t **DriverName)
{
    return EFI_UNSUPPORTED;
}

EFI_COMPONENT_NAME2_PROTOCOL gCoreCryptoDxeComponentName2Protocol = {
    &CoreCryptoGetDriverName,
    &CoreCryptoGetControllerName,
    "en"
};
