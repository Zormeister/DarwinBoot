// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_ARRAY__
#define __COREDARWINBOOT_ARRAY__

#include <CoreDarwinBoot/CDBBasicTypes.h>

CDB_API_BEGIN

/*!
 * @group Array
 * An array, because we need those.
 */

CDB_OBJECT_DEFINE(Array);

/* create array */
CDBArrayRef CDBArrayCreate(void **data, size_t count);

UInt32 CDBArrayGetCount(CDBArrayRef array);

void *CDBArrayGetDataAtIndex(size_t index);

CDB_API_END

#endif /* __COREDARWINBOOT_ARRAY__ */