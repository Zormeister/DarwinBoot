// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_OBJECT_HPP__
#define __COREDARWINBOOT_OBJECT_HPP__

#include <stdint.h>

namespace CDB {

class Object {
    public:
    Object();

    virtual bool init(void);

    virtual void free(void);

    virtual void retain(void);

    virtual void release(void);

    private:
    uint32_t fRetainCount;
};

}

#endif /* __COREDARWINBOOT_OBJECT_HPP__ */
