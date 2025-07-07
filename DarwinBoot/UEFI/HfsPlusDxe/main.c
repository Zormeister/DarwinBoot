// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "Platform/EFI/Types/Misc.h"
#include <Platform/EFI/Protocols/ComponentName.h>
#include <Platform/EFI/Protocols/DriverBinding.h>
#include <Platform/EFI/EFI.h>

EFI_DRIVER_BINDING_PROTOCOL gHfsPlusDxeDriverBindingProtocol;
EFI_COMPONENT_NAME2_PROTOCOL gHfsPlusDxeComponentName2Protocol;

EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable) {
    if (EFIInitialize(Handle, SystemTable)) {
        gHfsPlusDxeDriverBindingProtocol.ImageHandle = Handle;
        gHfsPlusDxeDriverBindingProtocol.DriverBindingHandle = Handle;

        BS->InstallProtocolInterface(Handle, &gEfiDriverBindingProtocolGuid, EFI_NATIVE_INTERFACE, &gHfsPlusDxeDriverBindingProtocol);
    } else {
        return EFI_ABORTED;
    }

    return 0;
}
