// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/Crypto.hpp>

using namespace CoreDarwinBoot::Digest;

Context::Context(Type type)
{
    m_type = type;
    
    switch (m_type) {
        case Type::SHA1:
            this->m_digestInfo = ccsha1_di();
            break;
        case Type::SHA256:
            this->m_digestInfo = ccsha256_di();
            break;
        case Type::SHA384:
            this->m_digestInfo = ccsha384_di();
            break;
        case Type::SHA512:
            this->m_digestInfo = ccsha512_di();
            break;
        case Type::SHA512_256:
            this->m_digestInfo = ccsha256_di();
            break;
        case Type::MD5:
            this->m_digestInfo = ccmd5_di();
            break;
    }

    m_digestCtx = (ccdigest_ctx_t)malloc(ccdigest_ctx_size(this->m_digestInfo->state_size, this->m_digestInfo->block_size));
}

void Context::update(const void *pData, size_t size)
{
    ccdigest_update(m_digestInfo, m_digestCtx, size, pData);
}

void Context::final(void *pDigest)
{
    ccdigest_final(m_digestInfo, m_digestCtx, pDigest);
}
