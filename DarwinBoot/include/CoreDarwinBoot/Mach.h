// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/Apple/MachO.h>

typedef struct _CDBMachFile *CDBMachFileRef;

CDBMachFileRef CDBMachFileCreateFromBinary(const UInt8 *Binary, size_t BinarySize);

MachCpuType CDBMachFileGetArchitecture(CDBMachFileRef);
MachCpuSubType CDBMachFileGetSubArchitecture(CDBMachFileRef);

bool CDBMachFileIsMultiArchitecture(CDBMachFileRef);

MachLoadCommand *CDBMachFileGetLoadCommand(CDBMachFileRef File, MachCommand Command);

