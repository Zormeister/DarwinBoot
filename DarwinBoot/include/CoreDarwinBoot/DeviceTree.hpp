// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __COREDARWINBOOT_DEVICETREE_HPP__
#define __COREDARWINBOOT_DEVICETREE_HPP__

#include <Platform/Apple/DeviceTree.h>

namespace CDB {

    namespace DeviceTree {

        class Node {
            public:
            Node(const char *name);

            bool addChild(Node *child);
        };

    }

};

#endif /* __COREDARWINBOOT_DEVICETREE_HPP__ */
