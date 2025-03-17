// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/LoadedImage.h>

/* Compatibility with POSIX-UEFI. */
EFI_SYSTEM_TABLE *ST = NULL;
EFI_BOOT_SERVICES *BS = NULL;
EFI_RUNTIME_SERVICES *RT = NULL;
EFI_HANDLE IM = NULL;
EFI_LOADED_IMAGE_PROTOCOL *LIP = NULL;
char *__argvutf8 = NULL;

/* implementing a vsnprintf-like thing is going to kill me */

// do we restart on darwinboot panic or nah, usually should be set to true on RELEASE builds
bool RestartOnPanic = true;

bool CDBInitializeUEFI(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    EFI_GUID LoadedImageProtocol = EFI_LOADED_IMAGE_PROTOCOL_GUID;

    /* we can't exactly scream for help right now, */
    if (SystemTable->Header.Signature != EFI_SYSTEM_TABLE_SIGNATURE) {
        return false;
    }
    if (SystemTable->BootServices == NULL || SystemTable->RuntimeServices == NULL || SystemTable->ConOut == NULL) {
        return false;
    }
    // init table vars
    ST = SystemTable;
    BS = SystemTable->BootServices;
    RT = SystemTable->RuntimeServices;
    /* should i even bother to verify the integrity of the system table */
    SystemTable->ConOut->Reset(SystemTable->ConOut, false);
    CDBLog("[CDB][UEFI]: Initialize has reached console out.");
    IM = ImageHandle;
    BS->HandleProtocol(ImageHandle, &LoadedImageProtocol, (void **)&LIP);
    CDBLog("[CDB][UEFI]: Obtained our Loaded Image Protocol instance");
    return true;
}

void *CDBAllocateMemory(const UInt32 size) {
    // Hypothetically should never happen.
    if (BS == NULL) { return NULL; }

    void *outbuffer;
    EFI_STATUS status = BS->AllocatePool(EfiLoaderData, size, &outbuffer);
    if (status != EFI_SUCCESS || outbuffer == NULL) {
        ST->ConOut->OutputString(ST->ConOut, WSTRING("[CDB][UEFI]: Memory Allocation failed.\n"));
        return NULL;
    }
    return outbuffer;
}

void CDBFreeMemory(void * mem) {
    // Hypothetically should never happen.
    if (BS == NULL) { return; }
    BS->FreePool(mem);
}

extern unsigned long strlen(const char *s);
extern int vprintf(const char *restrict, va_list);

void CDBLog(const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    char *buf = CDBAllocateMemory(strlen(fmt) + 64);
    snprintf(buf, strlen(fmt) + 6, "%s\n", fmt);
    vprintf(buf, va);
    CDBFreeMemory(buf);
    va_end(va);
}

void panic(const char *fmt, ...) {
    va_list va;
    va_start(va, fmt);
    char *buf = CDBAllocateMemory(strlen(fmt) + 64);
    snprintf(buf, strlen(fmt) + 64, "[DB][PANIC]: %s\n", fmt);
    vprintf(buf, va);
    CDBFreeMemory(buf);
    va_end(va);

    int to = RestartOnPanic ? 0 : 3000;
    int i = 1;
    do {
        i++;
    } while(i);
}

