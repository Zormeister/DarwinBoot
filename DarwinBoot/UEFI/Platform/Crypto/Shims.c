// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <Platform/DarwinBoot/EFI/CoreCrypto.h>
#include <Platform/EFI/EFI.h>
#include <string.h>
#include <panic.h>

//
// Why do we need shims on UEFI?
//
// CoreCryptoDxe provides the corecrypto project in a UEFI environment
// However, the only downside is that corecrypto needs an interface.
//
// Embeddeding the project into the various loaders seems like a waste of space, so,
// I settled on making a DXE.
//
// ARMwinBoot won't have this issue, I'll just embed the project like a static library.
//

CORECRYPTO_FUNCTIONS *EfiCoreCryptoFunctions;
EFI_SERVICE_BINDING_PROTOCOL *Hash2Binding;
EFI_RNG_PROTOCOL *RngProtocol;

static void ccrng_efi_init(void);

static bool UEFICryptoGetNativeProtocols(void)
{
    //
    // Locate the Hash2 protocol.
    //

#if 0
    if (BS->LocateProtocol(&gEfiHash2ServiceBindingProtocolGuid, NULL, (void **)&Hash2Binding)) {
        return false;
    }
#endif

    //
    // Initialise the RNG.
    //
    ccrng_efi_init();

    return true;
}

bool UEFICryptoInitShims(void)
{
    EFI_STATUS Status;
    CORECRYPTO_PROTOCOL *CryptoProtocol;

    //
    // Step 1. Check if we have CoreCryptoDxe available to us.
    //
#if 0
    if (BS->LocateProtocol(&gEfiCoreCryptoProtocolGuid, NULL, (void **)&CryptoProtocol)) {
        //
        // This moves onto using the native services.
        //
        return UEFICryptoGetNativeProtocols();
    }

    Status = CryptoProtocol->GetFunctionInterface(CryptoProtocol, &EfiCoreCryptoFunctions);
    if (Status) {
        return false;
    }
#endif

    return true;
}

#pragma mark - UEFI Native Protocol Abstraction (Hashing)



#pragma mark - UEFI Native Protocol Abstraction (RNG)

struct ccrng_efi_rng {
    CCRNG_STATE_COMMON;

    bool initialized;
    EFI_RNG_PROTOCOL *rng_protocol;
};

struct ccrng_efi_rng ccrng_efi_shim_rng = {NULL, false, NULL};

//
// Fallback in the event there are no (preferred) cryptographic PRNGs available
//
static int ccrng_efi_generate_timestamp(struct ccrng_state *rng, size_t outlen, void *out)
{
    struct ccrng_efi_rng *me = (struct ccrng_efi_rng *)rng;
    EFI_TIME Time;
    EFI_TIME_CAPABILITIES TimeCaps;
    uint8_t final[CCSHA256_OUTPUT_SIZE];

#if 0
    RT->GetTime(&Time, NULL);

    while (outlen >= CCSHA256_OUTPUT_SIZE) {
        ccdigest(ccsha256_di(), sizeof(EFI_TIME), &Time, out);
        RT->GetTime(&Time, NULL);

        outlen -= CCSHA256_OUTPUT_SIZE;
        out += CCSHA256_OUTPUT_SIZE;
    }

    if (outlen) {
        ccdigest(ccsha256_di(), sizeof(EFI_TIME), &Time, final);
        memcpy(out, final, outlen);
        memset(final, 0, sizeof(final));
    }
#endif

    return CCERR_OK;
}

static int ccrng_efi_generate(struct ccrng_state *rng, size_t outlen, void *out)
{
    struct ccrng_efi_rng *me = (struct ccrng_efi_rng *)rng;
    EFI_GUID algorithm = EFI_RNG_ALGORITHM_SP800_90_CTR_256_GUID;

    if (me->rng_protocol->GetRNG(me->rng_protocol, algorithm, outlen, out)) {
        return CCERR_INTERNAL;
    }

    return CCERR_OK;
}

static void ccrng_efi_init()
{
    if (ccrng_efi_shim_rng.initialized == false) {
#if 0
        if (BS->LocateProtocol(&gEfiRngProtocolGuid, NULL, (void **)&ccrng_efi_shim_rng.rng_protocol)) {
            panic("ccrng_efi_init: No system RNG protocol.");
        }
#endif

        ccrng_efi_shim_rng.generate = &ccrng_efi_generate;
        ccrng_efi_shim_rng.initialized = true;
    }
}

struct ccrng_state *ccrng(int *error)
{
    if (EfiCoreCryptoFunctions && EfiCoreCryptoFunctions->ccrng) {
        return EfiCoreCryptoFunctions->ccrng(error);
    } else {
        return (struct ccrng_state *)&ccrng_efi_shim_rng;
    }
}



//
// These shims make porting library code a whole lot more easier.
//


