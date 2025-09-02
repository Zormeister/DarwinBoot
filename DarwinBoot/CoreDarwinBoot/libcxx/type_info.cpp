// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <eh.h>
#include <libcxx/typeinfo>

const char * std::type_info::name()
{
    return __type_name;
}


