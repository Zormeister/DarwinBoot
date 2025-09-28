// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_BASE_HPP__
#define __COREDARWINBOOT_BASE_HPP__

#include <CoreDarwinBoot/CDBBasicTypes.h>

#if __cplusplus /* WHAT THE FUCK clangd, THIS IS A C++ HEADER FILE */

#define CDBTypeAlloc(type) (type *)type->getTypeInfo()->constructObject();

namespace CDB {

class Object;

/* yes. what else am i supposed to call this? */
class MetaClass {
    MetaClass(const char *name, size_t size, const MetaClass *superClass);

    public:
    Object *constructObject();

    private:
    const char *__name;
    size_t __size;
    size_t __instances;
};

    
/* The root of all objects. */
class Object {

};

};

#endif

#endif /* __COREDARWINBOOT_BASE_HPP__ */
