// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __libcxx_type_info__
#define __libcxx_type_info__

//
// do i want RTTI in a bootloader? fuck yes.
//

namespace std {

    class type_info {
        virtual ~type_info();

        bool operator == (const type_info &ti) const noexcept;
        bool operator != (const type_info &ti) const noexcept;

        bool before(const type_info &ti);

        size_t hash_code();

        const char *name();

        type_info(const type_info& ti) = delete;
        type_info& operator=(const type_info& ti) = delete; 

        /* Follow the Itanium C++ ABI, god I hope this works under the UEFI target. */
        private:
        const char *__type_name;
    };

}

#endif
