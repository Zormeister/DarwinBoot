// Copyright © 2024 Zormeister. All rights reserved.

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
