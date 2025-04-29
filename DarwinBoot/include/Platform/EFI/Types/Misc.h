// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <Platform/EFI/Types/Handle.h>

typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative,
} EFI_TIMER_DELAY;

typedef enum {
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef enum {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

struct {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UInt32 Attributes;
    UInt32 OpenCount;
} typedef EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} typedef EFI_RESET_TYPE;

struct {
    UInt8 Type;
    UInt32 IdSize;
    UInt8 Id[] __counted_by(IdSize);
} typedef EFI_VARIABLE_AUTHENTICATION_3_CERT_ID;
