// Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

.global _panic_halt

_panic_halt:
    wfe
    b _panic_halt