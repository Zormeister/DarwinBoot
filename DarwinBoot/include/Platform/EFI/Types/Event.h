// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

typedef void *EFI_EVENT;

typedef void (*EFI_EVENT_NOTIFY)(EFI_EVENT *Event, void *Context);

#define EVT_TIMER   0x80000000
#define EVT_RUNTIME 0x40000000

#define EVT_NOTIFY_WAIT   0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES     0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202
