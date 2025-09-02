// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

namespace CorePlatform {

    namespace Drivers {
        
        /* Interface class */
        class IDriver {
            public:
            IDriver();

            virtual const char *getDriverName() = 0;
        };

    }

}