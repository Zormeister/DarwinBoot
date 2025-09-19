// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __LIBCXXABI__
#define __LIBCXXABI__

#include <CoreDarwinBoot/CDBBasicTypes.h>

#if __cplusplus
#define LIBCXXABI_EXTERN extern "C"
#include <typeinfo>
#else
#define LIBCXXABI_EXTERN extern
#endif

//
// It looks like you're trying to commit a war crime, would you like some help?
//

//
// C++ runtime functions
//

#if __cplusplus

namespace __cxxabiv1 {

    //
    // This is not the full set of functions as defined in the Itanium ABI.
    //

    LIBCXXABI_EXTERN void __cxa_pure_virtual(void);

    LIBCXXABI_EXTERN void __cxa_deleted_virtual(void);

    LIBCXXABI_EXTERN void *__dso_handle;

    LIBCXXABI_EXTERN int __cxa_atexit(void (*destructor)(void *), void *arg, void *dso);
    LIBCXXABI_EXTERN void __cxa_finalize(void *f);

    LIBCXXABI_EXTERN int __cxa_guard_acquire(uint64_t *guard);
    LIBCXXABI_EXTERN void __cxa_guard_release(uint64_t *);
    LIBCXXABI_EXTERN void __cxa_guard_abort(uint64_t *);

    class __class_type_info : public std::type_info {};

    class __fundamental_type_info : public std::type_info {};

    class __array_type_info : public std::type_info {};

    class __function_type_info : public std::type_info {};

    class __enum_type_info : public std::type_info {};

    class __si_class_type_info : public __class_type_info {
        public:
        const __class_type_info *__base_type;
    };

    struct __base_class_type_info {
        public:
        const __class_type_info * __base_type;
        long __offset_flags;

        enum __offset_flags_masks {
	        __virtual_mask = 0x1,
	        __public_mask = 0x2,
	        __offset_shift = 8
	    };
    };
    
    class __vmi_class_type_info : public __class_type_info {
        public:
        uint32_t __flags;
        uint32_t __base_count;
        __base_class_type_info __base_info[1];

        enum __flags_masks {
	        __non_diamond_repeat_mask = 0x1,
	        __diamond_shaped_mask = 0x2
	    };
    };

    


}

#endif

#endif
