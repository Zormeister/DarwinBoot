// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __PLATFORM_DARWINBOOT_EFI_CORECRYPTO_H__
#define __PLATFORM_DARWINBOOT_EFI_CORECRYPTO_H__

#include <Platform/EFI/Types.h>
#include <corecrypto/ccaes.h>
#include <corecrypto/ccrng.h>
#include <corecrypto/ccsha1.h>
#include <corecrypto/ccsha2.h>

CDB_API_BEGIN

//
// an access interface for clients of CoreCryptoDxe.
//

//
// GUID:
// e4eb39c4-9958-40ed-b73a-545a67d087a2
//
// Does UEFI define any sort of standard for GUIDs?
//
#define EFI_CORECRYPTO_PROTOCOL_GUID \
    { 0xe4eb39c4, 0x9958, 0x40ed,         \
        { 0xb7, 0x3a, 0x54, 0x5a, 0x67, 0xd0, 0x87, 0xa2 } }

extern EFI_GUID gEfiCoreCryptoProtocolGuid;

//
// Function type definitions
//

typedef struct ccrng_state *(*CORECRYPTO_FUNCTIONS_CCRNG)(int *error);

typedef struct {
    UInt32 Revision;

    // AES functions
    struct ccmode_ecb *ccaes_ecb_encrypt; // probably wanted if other constructed modes are wanted
    struct ccmode_ecb *ccaes_ecb_decrypt; // probably wanted if other constructed modes are wanted

    struct ccmode_cbc *ccaes_cbc_encrypt; // Image3 payloads use CBC encryption
    struct ccmode_cbc *ccaes_cbc_decrypt; // Image3 payloads use CBC encryption

    struct ccmode_xts *ccaes_xts_encrypt; // FDE?
    struct ccmode_xts *ccaes_xts_decrypt; // FDE?

    // digest algorithms
    const struct ccdigest_info *ccsha1_di;       // Image3 uses SHA-1 hashed signatures
    const struct ccdigest_info *ccsha256_di;     // APFS can use SHA-256 for SSV
    const struct ccdigest_info *ccsha384_di;     // APFS can use SHA-384 for SSV
    const struct ccdigest_info *ccsha512_di;     // APFS can use SHA-512 for SSV
    const struct ccdigest_info *ccsha512_256_di; // APFS can use SHA-512/256 for SSV

    // RNG
    CORECRYPTO_FUNCTIONS_CCRNG ccrng;
} CORECRYPTO_FUNCTIONS;

typedef struct _CORECRYPTO_PROTOCOL CORECRYPTO_PROTOCOL;

struct _CORECRYPTO_PROTOCOL {
    UInt32 Revision;

    EFI_STATUS (*GetFunctionInterface)(CORECRYPTO_PROTOCOL *This, CORECRYPTO_FUNCTIONS **Functions);
};

CDB_API_END

#endif /* __PLATFORM_DARWINBOOT_EFI_CORECRYPTO_H__ */
