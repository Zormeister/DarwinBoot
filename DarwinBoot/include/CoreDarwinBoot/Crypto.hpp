// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_CRYPTO_HPP__
#define __COREDARWINBOOT_CRYPTO_HPP__

#include <CoreDarwinBoot/Base.hpp>

/*
 * What in the grand FUCK do we need corecrypto for?
 *
 * - Apple uses hashing and cryptographic functions to sign and validate
 *   not only firmware payloads, but also to sign DMG files.
 *
 * - This is particularly handy to get done if someone ever decides it's time
 *   to start signing DMGs and making the whole RAMDisk process, alongside
 *   firmware loading, secure(er) than if we just loaded blobs off of the disk.
 *
 * - To break it down, the Chunklist method of DMG authentication uses an RSA-2048
 *   signature alongside SHA2-256 hashing of every 'chunk', whilst the IMG4 method
 *   follows IMG4 rules for evaluating the integrity of the DMG.
 *
 * - IMG4 files are platform-configured, as Apple has overtime, changed the hashing
 *   and signing of the files themselves, for example, certain devices use SHA-1,
 *   whilst more of the later devices use SHA2-384. The RSA key size can /also/
 *   variate across devices, at least according to what I can find from a simple
 *   run of NM. I have yet to see any of these variances in the wild of studying
 *   the various DeviceTree files of Apple Silicon Macs.
 *
 * - libimg4 (Darwin 19) makes references to not only RSA, but also Elliptic Curve based
 *   signatures, I have zero idea if any of the EC signatures made it to production units,
 *   but you never know with our beloved fruit company.
 *
 * - I also /should/ import the DER encoding/decoding functionality from CC, as an IMG4
 *   is encoded into a DER blob, we quite literally couldn't interact with IMG4s without
 *   it.
 *
 */

#define CORECRYPTO_AVAILABLE __has_include(<corecrypto/cc.h>)

#if CORECRYPTO_AVAILABLE

extern "C" {
    #include <corecrypto/cc.h>
    #include <corecrypto/ccaes.h>
    #include <corecrypto/ccdigest.h>
    #include <corecrypto/ccsha1.h>
    #include <corecrypto/ccsha2.h>
    #include <corecrypto/ccmd5.h>
    #include <corecrypto/ccrng.h>
}

#endif /* CORECRYPTO_AVAILABLE */


#if __cplusplus

namespace CDB {

    namespace Digest {

        enum struct Type {
            MD5,
            SHA1,
            SHA256,
            SHA384,
            SHA512,
            SHA512_256,
        };

        class Context {

            public:
            Context(Type type);
            ~Context();

            void update(const void *pData, size_t size);

            void final(void *pDigest);

            private:
            const ccdigest_info *m_digestInfo;
            ccdigest_ctx_t m_digestCtx;
            Type m_type;
        };

        static void oneshot(Type digestType, const void *pData, size_t size, void *pDigest);
    }

}

#endif

#endif /* __COREDARWINBOOT_CRYPTO_HPP__ */
