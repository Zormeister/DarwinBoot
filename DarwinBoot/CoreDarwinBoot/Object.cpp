// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/Object.hpp>

using namespace CDB;

Object::Object()
{
    fRetainCount = 1;
}

bool Object::init(void)
{
    return true;
}

void Object::free()
{
    delete this;
}

void Object::retain()
{
    fRetainCount++;
}

void Object::release()
{
    fRetainCount--;

    if (fRetainCount == 0) {
        this->free();
    }
}
