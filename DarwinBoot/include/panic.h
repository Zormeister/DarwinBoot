// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PANIC_H__
#define __PANIC_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>

__BEGIN_DECLS

void panic(const char *fmt, ...);

__END_DECLS

#endif /* __PANIC_H__ */
