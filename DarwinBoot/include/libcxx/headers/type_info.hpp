// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libcxx_type_info__
#define __libcxx_type_info__

#include <stdint.h>

namespace std {

    class type_info {

    /* Itanium C++ ABI specifies the following as public APIs. */
    public:
        virtual ~type_info();

        bool operator == (const type_info &ti) const;
        bool operator != (const type_info &ti) const;

        bool before(const type_info &ti);

        size_t hash_code();

        const char *name();

    private:
        type_info(const type_info& ti) = delete;
        type_info& operator=(const type_info& ti) = delete; 

        /* Follow the Itanium C++ ABI, god I hope this works under the UEFI target. */
    private:
        const char *__type_name;
    };

}

#endif
