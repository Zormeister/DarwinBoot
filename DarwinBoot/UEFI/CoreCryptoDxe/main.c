// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/ComponentName.h>
#include <Platform/EFI/Protocols/DriverBinding.h>
#include <Platform/EFI/Protocols/ServiceBinding.h>

/* I only use this header for CORECRYPTO_AVAILABLE */
#include <CoreDarwinBoot/Crypto.h>

extern EFI_COMPONENT_NAME2_PROTOCOL gCoreCryptoDxeComponentName2Protocol;
extern EFI_SERVICE_BINDING_PROTOCOL gCoreCryptoDxeHashBindingProtocol;

EFI_STATUS EFIMain(EFI_HANDLE Handle, EFI_SYSTEM_TABLE *SystemTable)
{

#if CORECRYPTO_AVAILABLE

    if (EFIInitialize(Handle, SystemTable)) {
        // empty for now
        return EFI_SUCCESS;
    } else {
        return EFI_ABORTED;
    }

#else

    return EFI_ABORTED;

#endif
}
