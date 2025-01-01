# Copyright (C) 2024 Zormeister, Licensed under the GPLv3 or later.

# Establish foundational work
ifndef SRCROOT
SRCROOT := $(shell /bin/pwd)
endif

ifndef OBJROOT
OBJROOT := $(SRCROOT)/build/obj
endif

ifndef DSTROOT
DSTROOT := $(SRCROOT)/build/dst
endif