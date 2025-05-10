// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include "CoreDarwinBoot/CDBBasicTypes.h"
#include <Drivers/Driver.h>

enum {
    PhysicalRange,
    VirtualRange,
    BusRange,
    MMIORange,
} typedef RangeKind;

/* CPGetDeviceIdentity */
struct {
    UInt32 ChipID;
    UInt32 BoardID;
    UInt64 ECID;
    UInt32 ESEC;
    UInt32 EPRO;
    UInt32 SDOM;
    UInt32 PROD;
} typedef DeviceIdentity;

struct {
    UInt64 RangeStart;
    UInt64 RangeSize;
    RangeKind RangeKind;
    const char *RangeName;
} typedef MemoryRange;

#define MAX_DEV_RANGES 10

struct {
    const char * Compatible;
    MemoryRange Range;
} typedef PlatformDeviceDescriptor;

/* I feel like that's a sane value- let me know if this should be reduced or increased. */
#define MAX_MEM_RANGES 20

struct {
    UInt32 Version;

    /* callbacks */
#if __LP64__
    UInt64 (*PhysicalToVirtualAddress)(UInt64 PhysicalAddress);
    UInt64 (*VirtualToPhysicalAddress)(UInt64 VirtualAddress);
#else
    UInt32 (*PhysicalToVirtualAddress)(UInt32 PhysicalAddress);
    UInt32 (*VirtualToPhysicalAddress)(UInt32 VirtualAddress);
#endif

    /* mapper data */
    MemoryRange AvailableRanges[MAX_MEM_RANGES];
} typedef PageMapper;

extern PageMapper gMapper;

bool CPInitialize(MemoryRange EarlyMem, PlatformDeviceDescriptor *Devices);

void AddRangeToPageMap(MemoryRange NewRange);

UInt64 PhysicalAddressToVirutal(UInt64 PA);
UInt64 VirtualAddressToPhysical(UInt64 VA);

/*!
 * @function CPGetDeviceIdentity
 *
 * @abstract This is setup in a similar scheme to the IMG4 identity system
 * @result Returns the 'identity' of the device.
 */
DeviceIdentity *CPGetDeviceIdentity(void);

bool CPSerialDriverAvailable(void);

/* This is needed for BCM2835 Aux UART, we need to interface with the aux controller. */
PlatformDriver *CPGetDriverHandle(const char *DriverName);

bool CPRegisterDriver(PlatformDriver *Driver);
