// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_EFI_HPP__
#define __COREDARWINBOOT_EFI_HPP__

#include <CoreDarwinBoot/Base.hpp>
#include <Platform/EFI/EFI.h>

#if __COREDARWINBOOT_CFG_UEFI__

namespace CDB {

    namespace EFI {
        bool Initialize(EFI_HANDLE hHandle, EFI_SYSTEM_TABLE *pSystemTable);
    
        class Interface : public Object {
            /* Create an EFI interface object. */
            static Interface *withSystemTableAndHandle(EFI_SYSTEM_TABLE *pSystemTable, EFI_HANDLE hHandle);

            public:
            bool initWithSystemTableAndHandle(EFI_SYSTEM_TABLE *pSystemTable, EFI_HANDLE hHandle);

            EFI_SYSTEM_TABLE *getSystemTable(void);

            EFI_CONFIGURATION_TABLE *getConfigurationTable(guid_t *pGUID);

            void *getProtocolByGUID(guid_t *pGUID);

            private:
            EFI_SYSTEM_TABLE *fpSystemTable;
            EFI_HANDLE fHandle;
            EFI_BOOT_SERVICES *fpBootServices;
        };


        extern Interface *getSystemInterface(void);
    }

};

#endif /* __COREDARWINBOOT_CFG_UEFI__ */

#endif /* __COREDARWINBOOT_EFI_HPP__ */
