// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __LIBCXXABI__
#define __LIBCXXABI__

#include <CoreDarwinBoot/CDBBasicTypes.h>

/*
 * @group cxxabi
 *
 * A non-compliant budget version of the Itanium ABI, so that the C++ code doesn't die.
 *
 */


#if __cplusplus
#define LIBCXXABI_EXTERN extern "C"
#else
#define LIBCXXABI_EXTERN extern
#endif

/*
 * It looks like you're trying to commit a war crime, would you like some help?
 */

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
}

#endif

#endif
