// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Platform/EFI/EFI.h>

/* I only use this header for CORECRYPTO_AVAILABLE */
#include <CoreDarwinBoot/Crypto.h>

#if CORECRYPTO_AVAILABLE
    #include <corecrypto/ccmd5.h>
    #include <corecrypto/ccsha1.h>
    #include <corecrypto/ccsha2.h>

//
// Shared logic between both instances of Hash Protocol.
//

const struct ccdigest_info *CcDigestGetHashFromGuid(EFI_GUID *Algorithm)
{
    if (EFIGuidMatches(&gEfiHashAlgorithmSha1Guid, Algorithm)) {
        return ccsha1_di();
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha224Guid, Algorithm)) {
        return ccsha224_di();
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha256Guid, Algorithm)) {
        return ccsha256_di();
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha384Guid, Algorithm)) {
        return ccsha384_di();
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha512Guid, Algorithm)) {
        return ccsha512_di();
    } else if (EFIGuidMatches(&gEfiHashAlgorithmMd5Guid, Algorithm)) {
        return ccmd5_di();
    }

    return NULL;
}

UIntN CcDigestGetHashSizeFromGuid(EFI_GUID *Algorithm)
{
    if (EFIGuidMatches(&gEfiHashAlgorithmSha1Guid, Algorithm)) {
        return ccsha1_di()->output_size;
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha224Guid, Algorithm)) {
        return ccsha224_di()->output_size;
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha256Guid, Algorithm)) {
        return ccsha256_di()->output_size;
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha384Guid, Algorithm)) {
        return ccsha384_di()->output_size;
    } else if (EFIGuidMatches(&gEfiHashAlgorithmSha512Guid, Algorithm)) {
        return ccsha512_di()->output_size;
    } else if (EFIGuidMatches(&gEfiHashAlgorithmMd5Guid, Algorithm)) {
        return ccmd5_di()->output_size;
    }

    return 0;
}

    #pragma mark Hash Protocol

#endif
