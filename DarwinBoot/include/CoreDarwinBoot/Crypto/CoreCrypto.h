// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

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

    #include <corecrypto/cc.h>
    #include <corecrypto/ccdigest.h>

#endif /* CORECRYPTO_AVAILABLE */
