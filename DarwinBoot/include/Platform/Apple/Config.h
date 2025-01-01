// Copyright © 2024 Zormeister.

/*
 * This file is part of DarwinBoot.
 
 * DarwinBoot is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 * DarwinBoot is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License along with DarwinBoot. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#define BOOT_PLIST_LOCATION "/Library/Preferences/SystemConfiguration/com.apple.Boot.plist"

/* this is the path as of Darwin 24 and some older betas of Big Sur. */
#define KERNEL_COLLECTION_PATH "/System/Library/KernelCollections/BootKernelExtensions.kc"
/* I /swear/ it was called BootKernelCollection prior to macOS Sequoia */
#define KERNEL_COLLECTION_OLD_PATH "/System/Library/KernelCollections/BootKernelCollection.kc"

/* ah prelinkedkernel... rest in peace. */
#define KERNEL_PRELINKED_PATH "/System/Library/PrelinkedKernels/prelinkedkernel"

/* TODO: I need to live-translate these to the respective SoC kernel while booting */
/* EG: kernel.release.bcm2837 or in my case kernel.development.bcm2712 */
#define KERNEL_PATH "/System/Library/Kernels/kernel"

/* I believe these also had the .VARIANT.SoC style naming, on iOS of course. */
#define KERNEL_OLD_PATH "/mach_kernel"

/* should read this at runtime */
#define SYSTEM_VERSION_PATH "/System/Library/CoreServices/SystemVersion.plist"