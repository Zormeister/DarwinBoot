// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <stdlib.h>
#include <CoreDarwinBoot/Runtime.h>

static uint32_t __CDBTypeCount;

void __CDBRegisterRuntimeClass(CDBRuntimeClass *type)
{
    type->TypeID = __CDBTypeCount++;
}

CDBTypeRef __CDBRuntimeObjectCreate(CDBRuntimeClass *type, size_t objSize)
{
    struct __CDBRuntimeHeader *hdr;

    hdr = malloc(objSize);
    hdr->__type = type;
    hdr->__objSize = objSize;
    hdr->__retainCount = 1; /* Start off with a retain count of one. */

    return hdr;
}

void CDBRelease(CDBTypeRef type)
{
    struct __CDBRuntimeHeader *hdr = (struct __CDBRuntimeHeader *)type;

    if (hdr->__retainCount == 1) {
        /* The object is no longer in use! Kill it! */
        hdr->__type->Release(type);
    } else {
        hdr->__retainCount--;
    }
}

CDBTypeRef CDBRetain(CDBTypeRef type)
{
    struct __CDBRuntimeHeader *hdr = (struct __CDBRuntimeHeader *)type;

    hdr->__retainCount++;

    return type;
}
