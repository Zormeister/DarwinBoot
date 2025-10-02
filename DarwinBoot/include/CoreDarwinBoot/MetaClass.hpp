// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_METACLASS_HPP__
#define __COREDARWINBOOT_METACLASS_HPP__

#include <CoreDarwinBoot/CDBBasicTypes.h>

#define CDBTypeAlloc(type) (type *)type->getMetaClass()->constructObject();

#define CDBDefineMetaClassAndStructors(type) \
    private: \
    static const MetaClass * superClass; \
    public: \
    static const MetaClass *metaClass; \
    class MetaClass : public CDB::MetaClass { \
       MetaClass(); \
       virtual BaseObject *constructObject() override; \
    }; \
    virtual const CDB::MetaClass *getMetaClass(void);

#define CDBDefineOperators(type) \
    operator new { \
        return malloc(sizeof(type))\
    } \

namespace CDB {

/* forward declaration */
class BaseObject;

class MetaClass {
    public:
    MetaClass();
    MetaClass(const char *name, size_t size, const MetaClass *superClass);
    virtual ~MetaClass();

    public:
    virtual BaseObject *constructObject(void);

    const char *getClassName(void);

    uint32_t getClassSize(void);

    private:
    const MetaClass *__superClass;
    const char *__name;
    uint32_t __size;
    uint32_t __instances;
};

class BaseObject {
    BaseObject *dynamicCast(const MetaClass *toClass);
};

}

#endif /* __COREDARWINBOOT_METACLASS_HPP__ */
