// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

CDB_API_BEGIN

void CDBLog(const char *fmt, ...);

void panic(const char *fmt, ...);

CDB_API_END
