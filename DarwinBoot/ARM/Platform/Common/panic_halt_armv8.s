// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

.global _panic_halt

_panic_halt:
    wfe
    b _panic_halt