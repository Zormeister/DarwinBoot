// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

// CoreCrypto API wrappers

// mmmm this isnt ever used, maybe i should fidget with it. who knows.
#define CC_DARWINBOOT 1

#if __arm__ || __arm64__
#define CC_IBOOT 1
#endif

#if __x86_64__ || __i386__
// What's the bet that they use corecrypto for the UEFI Crypto Services?
#define CC_EFI 1
#endif

#define WOOPS_WE_DONT_HAVE_IT_PULLED_IN_YET 1

#ifndef WOOPS_WE_DONT_HAVE_IT_PULLED_IN_YET
#include <corecrypto/cc.h>
#endif