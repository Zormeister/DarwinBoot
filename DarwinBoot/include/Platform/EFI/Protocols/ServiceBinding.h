// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

/* The Service Binding protocol is an abstract interface. No GUID for it. */

typedef struct _EFI_SERVICE_BINDING_PROTOCOL EFI_SERVICE_BINDING_PROTOCOL;

struct _EFI_SERVICE_BINDING_PROTOCOL {
    EFI_STATUS (*CreateChild)(EFI_SERVICE_BINDING_PROTOCOL *This, EFI_HANDLE *ChildHandle);
    EFI_STATUS (*DestroyChild)(EFI_SERVICE_BINDING_PROTOCOL *This, EFI_HANDLE *ChildHandle);
};
