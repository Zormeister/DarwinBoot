// Copyright (C) 2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#include <CoreDarwinBoot/CoreDarwinBoot.h>
#include <CoreDarwinBoot/FileSystem.h>
#include <Platform/EFI/EFI.h>
#include <Platform/EFI/Protocols/File.h>
#include <Platform/EFI/Protocols/SimpleFileSystem.h>
#include <stdlib.h>

/* Who the hell would have over 64 FSes on one computer? */
/* Let me know if this needs to change at all. */
#define kMaxFileSystems 64

#if CONFIG_DEVELOPMENT || CONFIG_DEBUG
    #define DBG_TRACE(msg, args...) CDBLog("FS(%s): " msg, __FUNCTION__, ##args)
#else
    /* if/when DarwinBoot reaches production, make this not print. */
    #define DBG_TRACE(msg, args...) CDBLog("FS(%s): " msg, __FUNCTION__, ##args)
#endif

struct _CDBFileSystem {
    EFI_FILE_PROTOCOL *RootFile;
    char *FileSystemName; /* this is a char pointer because it's decoded from the wchar_t version. */
    EFI_FILE_SYSTEM_INFO *FSInfo;

    bool IsBootable; /* TODO: Integrate with Bootability */
};

struct _CDBFile {
    /* bare minimum */
    EFI_FILE_PROTOCOL *FileProtocol;

    /* additional details */
    size_t FileSize;
};

/* This should be initialised at FS Init. */
static CDBFileSystemRef _bootVolume;
static CDBFileSystemRef _fileSystems[kMaxFileSystems]; // This is a large variable, but it's better to have it here than not.

/*
 * This will work for the on-disk loader.
 *
 * On-ESP loader will need guidance on the location of the Root/Boot volume for Darwin.
 *
 * On-ESP loader will be overall compatible anyways, I just need to workout how to do GUI + prompt rendering.
 */
CDBFileSystemRef CDBFileSystemGetBootVolume(void) { return _bootVolume; }

#pragma mark CDBFileSystemOpenFile

CDBFileRef CDBFileSystemOpenFile(CDBFileSystemRef FileSystem, const char *Path, UInt32 Mode)
{
    UInt32 EFIFileMode;
    wchar_t *FilePath;
    EFI_FILE_PROTOCOL *File;

    if (Mode & kCDBFileModeRead) {
        DBG_TRACE("<%p> :: opening %s in Read mode", FileSystem, Path);
        EFIFileMode |= EFI_FILE_MODE_READ;
    }
    if (Mode & kCDBFileModeWrite) {
        DBG_TRACE("<%p> :: opening %s in Write mode", FileSystem, Path);
        EFIFileMode |= EFI_FILE_MODE_WRITE;
    }
    if (Mode & kCDBFileModeCreate) {
        DBG_TRACE("<%p> :: opening %s in Create mode", FileSystem, Path);
        EFIFileMode |= EFI_FILE_MODE_CREATE;
    }

    EFIASCIIToWideString(Path, &FilePath, kEFIEncodeInvertSlashes);

    EFI_STATUS status = FileSystem->RootFile->Open(FileSystem->RootFile, &File, FilePath, EFIFileMode, EFI_FILE_SYSTEM);
    if (status) {
        CDBLog("FS (%s): Failed to open file (%llX)", FileSystem->FileSystemName, status);
        free(FilePath);
        return NULL;
    }

    return NULL;
}

static CDBFileSystemRef UEFIFileSystemCreate(EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Protocol)
{
    if (Protocol) {
        CDBFileSystemRef newFS = (CDBFileSystemRef)malloc(sizeof(struct _CDBFileSystem));
        EFI_STATUS status = Protocol->OpenVolume(Protocol, &newFS->RootFile);
        if (status) {
            CDBLog("FS(%s): Failed to open the volume, (0x%llX)", __FUNCTION__, (status & ~EFI_HIGH_BIT));
            free(newFS);
            return NULL;
        }

        DBG_TRACE("Created new FS ref @ <%p>", newFS);
        DBG_TRACE("FS Root @ <%p>.", newFS->RootFile);

        /* Get the Volume name */
        EFI_FILE_SYSTEM_INFO *FSInfo;
        UIntN BufferSize;
        EFI_GUID Guid = EFI_FILE_SYSTEM_INFO_ID;

        status = newFS->RootFile->GetInfo(newFS->RootFile, &Guid, &BufferSize, NULL);
        if (status == EFI_BUFFER_TOO_SMALL) {
            FSInfo = malloc(BufferSize);
            status = newFS->RootFile->GetInfo(newFS->RootFile, &Guid, &BufferSize, FSInfo);
            if (status) {
                CDBLog("FS(%s): Failed to get File System Info (%llX)", __FUNCTION__, status);
                return newFS;
            }
            newFS->FSInfo = FSInfo;
        }

        EFIWideStringToASCII(FSInfo->VolumeName, &newFS->FileSystemName, kEFIEncodeFlagsNone);

        DBG_TRACE("New FS Volume Name: %s", newFS->FileSystemName);

        return newFS;
    } else {
        DBG_TRACE("Protocol is NULL.");
        return NULL;
    }
}

void UEFIFileSystemFree(CDBFileSystemRef FSRef)
{
    free(FSRef->FileSystemName);
    free(FSRef->FSInfo);
    free(FSRef);
}

void UEFIFileSystemInit(void)
{
    EFI_HANDLE Handles[kMaxFileSystems];
    EFI_GUID Guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
    UIntN HandleSize = 0;
    size_t NumHandles = 0;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Protocol = NULL;

    /* Start by finding the 'Boot Volume' */
    DBG_TRACE("Locating Boot Volume...");
    BS->HandleProtocol(LIP->DeviceHandle, &Guid, (void **)&Protocol);
    _bootVolume = UEFIFileSystemCreate(Protocol);

    if (_bootVolume) {
        DBG_TRACE("Successfully located the Boot Volume.");
    } else {
        panic("FS(%s): Failed to locate the Boot Volume.", __FUNCTION__);
    }

    /* TODO: Can someone PLEASE give me a direction on how to enumerate the available FSes. I can't find shit. */

    // BS->LocateHandle(AllHandles, &Guid, NULL, &HandleSize, Handles);
    // CDBLog("FS: HandleSize is 0x%x, (%d)", HandleSize, HandleSize);

    /*
    NumHandles = HandleSize / sizeof(EFI_HANDLE);
    for (int i = 0; i < NumHandles; i++) {
        CDBLog("FS: At index %d", i);
        EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Protocol = NULL;
        EFI_STATUS stat = BS->OpenProtocol(Handles[i], &Guid, (void **)&Protocol, IH, NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);
        if (Protocol) {
            _fileSystems[i] = malloc(sizeof(struct _CDBFileSystem));
            Protocol->OpenVolume(Protocol, &_fileSystems[i]->RootFile);
            CDBLog("FS: Simple FS Protocol @ <%p>", Protocol);
            CDBLog("FS: Root File Protocol @ <%p>", _fileSystems[i]->RootFile);
        } else {
            CDBLog("FS: 0x%llX",stat);
        }
    }
    */

    /* bloody hell. */
}
