// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include "Platform/EFI/Types/Status.h"
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/Hash.h>
#include <Platform/EFI/Protocols/ServiceBinding.h>

/* I only use this header for CORECRYPTO_AVAILABLE */
#include <CoreDarwinBoot/Crypto/CoreCrypto.h>
#include <corecrypto/ccdigest.h>
#include <stdlib.h>

#if CORECRYPTO_AVAILABLE
#include <corecrypto/ccmd5.h>
#include <corecrypto/ccsha1.h>
#include <corecrypto/ccsha2.h>

//
// CoreCrypto hashing services
//

extern const struct ccdigest_info *CcDigestGetHashFromGuid(const EFI_GUID *Algorithm);
extern UIntN CcDigestGetHashSizeFromGuid(const EFI_GUID *Algorithm);

#pragma mark Hash Protocol

EFI_STATUS CcHashProtocolGetHashSize(const EFI_HASH_PROTOCOL *This, const EFI_GUID *HashGuid, UIntN *HashSize)
{
    if (HashGuid == NULL || HashSize == NULL) {
        return EFI_INVALID_PARAMETER;
    }

    UIntN Size = CcDigestGetHashSizeFromGuid(HashGuid);
    if (Size == 0) {
        return EFI_UNSUPPORTED;
    }

    *HashSize = Size;
    return EFI_SUCCESS;
}

EFI_STATUS CcHashProtocolHash(const EFI_HASH_PROTOCOL *This, const EFI_GUID *HashGuid,
    bool Extend, const UInt8 *Message, UInt64 MessageSize,
    EFI_HASH_OUTPUT *Hash)
{
    const struct ccdigest_info *di;

    if (HashGuid == NULL || Message == NULL || Hash == NULL) {
        return EFI_INVALID_PARAMETER;
    }

    di = CcDigestGetHashFromGuid(HashGuid);
    if (di == NULL) {
        return EFI_UNSUPPORTED;
    }

    ccdigest_di_decl(di, ctx);
    ccdigest_init(di, ctx);
    if (Extend) {
        /* I use Md5 hash as a generic field. */
        memcpy(ccdigest_state(di, ctx), Hash->Md5Hash, di->output_size);
    }
    ccdigest_update(di, ctx, MessageSize, Message);
    ccdigest_final(di, ctx, Hash->Md5Hash);

    return EFI_SUCCESS;
}

#pragma mark Hash Binding Service

EFI_SERVICE_BINDING_PROTOCOL gCoreCryptoDxeHashBindingProtocol;

// I hope this doesn't ever become an issue.
#define kCoreCryptoHashBindingMagic 0x63636431

struct {
    UInt32 Magic;
    EFI_HASH_PROTOCOL Protocol;
} typedef CC_HASH_HANDLE;

/* How NOT to implement a Service Binding Protocol: */

EFI_STATUS CoreCryptoHashBindingCreateChild(EFI_SERVICE_BINDING_PROTOCOL *This, EFI_HANDLE *Child)
{
    //
    // Create a handle for UEFI.
    //

    Child = malloc(sizeof(CC_HASH_HANDLE)); /* I know that this is an opaque type. */
    CC_HASH_HANDLE *Hndl = (CC_HASH_HANDLE *)Child;
    Hndl->Magic = kCoreCryptoHashBindingMagic;

    Hndl->Protocol.GetHashSize = &CcHashProtocolGetHashSize;
    Hndl->Protocol.Hash = &CcHashProtocolHash;

    EFI_STATUS status = BS->InstallProtocolInterface(Child, &gEfiHashProtocolGuid, EFI_NATIVE_INTERFACE, &Hndl->Protocol);
    if (status) {
        free(Child);
        return status;
    }

    return EFI_SUCCESS;
};

EFI_STATUS CoreCryptoHashBindingDestroyChild(EFI_SERVICE_BINDING_PROTOCOL *This, EFI_HANDLE *Child)
{
    CC_HASH_HANDLE *Hndl = (CC_HASH_HANDLE *)Child;

    /* Quickly check if we exist */
    if (Hndl->Magic == kCoreCryptoHashBindingMagic) {
        free(Hndl);
        return EFI_SUCCESS;
    }

    return EFI_INVALID_PARAMETER;
}

EFI_SERVICE_BINDING_PROTOCOL gCoreCryptoDxeHashBindingProtocol = {
    &CoreCryptoHashBindingCreateChild,
    &CoreCryptoHashBindingDestroyChild,
};

#endif
