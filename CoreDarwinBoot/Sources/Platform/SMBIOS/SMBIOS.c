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

#include <CoreDarwinBoot/CoreDarwinBoot.h>

const char *CDBSMBIOSGetString(SMBIOSTableHeader *header, UInt32 stringIdx) {
    UInt8 *Raw = (UInt8 *)header;
    UInt32 size = header->Length;
}
