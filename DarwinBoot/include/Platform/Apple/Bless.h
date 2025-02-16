// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once

// efi-boot-device NVRAM variable contents
// array {
//   dict {
//     dict : IOMatch {
//       string : IOProviderClass
//       dict : IOPropertyMatch {
//         string : UUID  - root volume?
//	      }
//     }
//     string : BLLastBSDName - root volume BSD name?
//   }
//   dict {
//     string : IOEFIDevicePathType
//     string : Path
//   }
