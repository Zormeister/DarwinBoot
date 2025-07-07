// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <Platform/EFI/Types.h>

#define EFI_HASH_ALGORITHM_SHA1_GUID \
  {0x2ae9d80f,0x3fb2,0x4095, \
    {0xb7,0xb1,0xe9,0x31,0x57,0xb9,0x46,0xb6}}

#define EFI_HASH_ALGORITHM_SHA224_GUID \
  {0x8df01a06,0x9bd5,0x4bf7, \
    {0xb0,0x21,0xdb,0x4f,0xd9,0xcc,0xf4,0x5b}}

#define EFI_HASH_ALGORITHM_SHA256_GUID \
  {0x51aa59de,0xfdf2,0x4ea3, \
    {0xbc,0x63,0x87,0x5f,0xb7,0x84,0x2e,0xe9}}

#define EFI_HASH_ALGORITHM_SHA384_GUID \
  {0xefa96432,0xde33,0x4dd2, \
    {0xae,0xe6,0x32,0x8c,0x33,0xdf,0x77,0x7a}}

#define EFI_HASH_ALGORITHM_SHA512_GUID \
  {0xcaa4381e,0x750c,0x4770, \
    {0xb8,0x70,0x7a,0x23,0xb4,0xe4,0x21,0x30}}

#define EFI_HASH_ALGORITHM_MD5_GUID \
  {0xaf7c79c,0x65b5,0x4319, \
    {0xb0,0xae,0x44,0xec,0x48,0x4e,0x4a,0xd7}}

#define EFI_HASH_SERVICE_BINDING_PROTOCOL_GUID \
  {0x42881c98,0xa4f3,0x44b0,\
    {0xa3,0x9d,0xdf,0xa1,0x86,0x67,0xd8,0xcd}}

#define EFI_HASH_PROTOCOL_GUID \
  {0xc5184932,0xdba5,0x46db,\
    {0xa5,0xba,0xcc,0x0b,0xda,0x9c,0x14,0x35}}

extern EFI_GUID gEfiHashServiceBindingProtocolGuid;
extern EFI_GUID gEfiHashProtocolGuid;

extern EFI_GUID gEfiHashAlgorithmSha1Guid;
extern EFI_GUID gEfiHashAlgorithmSha224Guid;
extern EFI_GUID gEfiHashAlgorithmSha256Guid;
extern EFI_GUID gEfiHashAlgorithmSha384Guid;
extern EFI_GUID gEfiHashAlgorithmSha512Guid;
extern EFI_GUID gEfiHashAlgorithmMd5Guid;

typedef UInt8 EFI_MD5_HASH[16];
typedef UInt8 EFI_SHA1_HASH[20];
typedef UInt8 EFI_SHA224_HASH[28];
typedef UInt8 EFI_SHA256_HASH[32];
typedef UInt8 EFI_SHA384_HASH[48];
typedef UInt8 EFI_SHA512_HASH[64];

typedef union {
    EFI_MD5_HASH *Md5Hash;
    EFI_SHA1_HASH *Sha1Hash;
    EFI_SHA224_HASH *Sha224Hash;
    EFI_SHA256_HASH *Sha256Hash;
    EFI_SHA384_HASH *Sha384Hash;
    EFI_SHA512_HASH *Sha512Hash;
} EFI_HASH_OUTPUT;

typedef struct _EFI_HASH_PROTOCOL EFI_HASH_PROTOCOL;

struct _EFI_HASH_PROTOCOL {
    EFI_STATUS (*GetHashSize)(const EFI_HASH_PROTOCOL *This, const EFI_GUID *HashGuid, UIntN *HashSize);
    EFI_STATUS (*Hash)(const EFI_HASH_PROTOCOL *This, const EFI_GUID *HashGuid, bool Extend, const UInt8 *Message, UInt64 MessageSize, EFI_HASH_OUTPUT *Hash);
};

#define EFI_HASH2_SERVICE_BINDING_PROTOCOL_GUID \
  {0xda836f8d,0x217f,0x4ca0, \
    {0x99,0xc2,0x1c,0xa4,0xe1,0x60,0x77,0xea}}

#define EFI_HASH2_PROTOCOL_GUID \
  {0x55b1d734,0xc5e1,0x49db, \
    {0x96,0x47,0xb1,0x6a,0xfb,0xe,0x30,0x5b}}

extern EFI_GUID gEfiHash2ServiceBindingProtocolGuid;
extern EFI_GUID gEfiHash2ProtocolGuid;

typedef UInt8 EFI_MD5_HASH2[16];
typedef UInt8 EFI_SHA1_HASH2[20];
typedef UInt8 EFI_SHA224_HASH2[28];
typedef UInt8 EFI_SHA256_HASH2[32];
typedef UInt8 EFI_SHA384_HASH2[48];
typedef UInt8 EFI_SHA512_HASH2[64];

typedef union {
    EFI_MD5_HASH2 Md5Hash;
    EFI_SHA1_HASH2 sSha1Hash;
    EFI_SHA224_HASH2 Sha224Hash;
    EFI_SHA256_HASH2 Sha256Hash;
    EFI_SHA384_HASH2 Sha384Hash;
    EFI_SHA512_HASH2 Sha512Hash;
} EFI_HASH2_OUTPUT;

typedef struct _EFI_HASH2_PROTOCOL EFI_HASH2_PROTOCOL;

struct _EFI_HASH2_PROTOCOL {
    EFI_STATUS (*GetHashSize)(const EFI_HASH2_PROTOCOL *This, const EFI_GUID *HashAlgorithm, UIntN *HashSize);
    EFI_STATUS (*Hash)(const EFI_HASH2_PROTOCOL *This, const EFI_GUID *HashAlgorithm, const UInt8 *Message, UInt64 MessageSize, EFI_HASH2_OUTPUT *Hash);
    EFI_STATUS (*HashInit)(const EFI_HASH2_PROTOCOL *This, const EFI_GUID *HashAlgorithm);
    EFI_STATUS (*HashUpdate)(const EFI_HASH2_PROTOCOL *This, const UInt8 *Message, UInt64 MessageSize);
    EFI_STATUS (*HashFinal)(const EFI_HASH2_PROTOCOL *This, const EFI_HASH2_OUTPUT *Hash);
};
