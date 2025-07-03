// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/Apple/MachO.h>

#define kBootKernelCollectionPath "/System/Library/KernelCollections/BootKernelCollection.kc"
#define kSystemKernelCollectionPath "/System/Library/KernelCollections/SystemKernelCollection.kc"
#define kAuxiliaryKernelCollectionPath "/Library/KernelCollections/AuxiliaryKernelCollection.kc"

/* KernelCollections aren't overtly special, they follow the Mach-O format directly */
