// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/BootArgs.h>
#include <CoreDarwinBoot/CPUInfo.h>
#include <CoreDarwinBoot/DeviceTree.h>
#include <CoreDarwinBoot/libc_compat.h>

void CDBLogv(const char *fmt, va_list va);
void CDBLog(const char *fmt, ...);

//extern void *CDBAllocateMemory(size_t size);
//extern void CDBFreeMemory(void *p);

extern void panic(const char *fmt, ...);
