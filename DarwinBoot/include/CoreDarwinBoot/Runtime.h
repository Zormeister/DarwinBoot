// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_RUNTIME__
#define __COREDARWINBOOT_RUNTIME__

#include <CoreDarwinBoot/CDBBasicTypes.h>

/*!
 * @group Runtime
 * The basic building blocks of CoreDarwinBoot and all of it's libraries. 
 */

typedef void *CDBTypeRef;

typedef uint32_t CDBTypeID;

typedef void (*CDBReleaseCallback)(CDBTypeRef type);
typedef CDBTypeRef (*CDBAllocateCallback)(void);

struct _CDBRuntimeClass {
    const char *Name;
    CDBTypeID TypeID;
    CDBReleaseCallback Release;
    CDBAllocateCallback Allocate;
} typedef CDBRuntimeClass;

struct __CDBRuntimeHeader {
    CDBRuntimeClass *__type;
    size_t __objSize;
    uint32_t __retainCount;
};

CDBTypeRef CDBRetain(CDBTypeRef type);
void CDBRelease(CDBTypeRef type);

void __CDBRegisterRuntimeClass(CDBRuntimeClass *type);
CDBTypeRef __CDBRuntimeObjectCreate(CDBRuntimeClass *type, size_t objSize);

#endif /* __COREDARWINBOOT_RUNTIME__ */
