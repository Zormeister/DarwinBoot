// Copyright (C) 2024-2025 Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#pragma once
#include <CoreDarwinBoot/CDBBasicTypes.h>

/* 0xfeedface & 0xcefaedfe */
#define MACH_MAGIC 0xFEEDFACE
#define MACH_CIGAM 0xCEFAEDFE

/* 0xfeedface & 0xcefaedfe */
#define MACH_MAGIC_64 0xFEEDFACF
#define MACH_CIGAM_64 0xCFFAEDFE

typedef UInt32 MachCpuType;
typedef UInt32 MachCpuSubType;

/* Mach-O header go brrrr */
struct {
    UInt32 Magic;
    UInt32 CpuType;
    UInt32 CpuSubType;
    UInt32 FileType;
    UInt32 LoadCommandCount;
    UInt32 LoadCommandsSize;
    UInt32 Flags;
} typedef MachOHeader;

struct {
    UInt32 Magic;
    MachCpuType CpuType;
    MachCpuSubType CpuSubType;
    UInt32 FileType;
    UInt32 LoadCommandCount;
    UInt32 LoadCommandsSize;
    UInt32 Flags;
    UInt32 Rsvd;
} typedef MachOHeader64;

/* https://github.com/apple-oss-distributions/cctools/blob/cctools-1010.6/include/mach/machine-cctools.h#L139 */
enum {
    MachAbiX64 = 0x1000000,
    MachCpuTypeVax = 1,
    MachCpuTypeRomp = 2,
    MachCpuTypeI386 = 7,
    MachCpuTypeX86_64 = MachCpuTypeI386 | MachAbiX64,
    MachCpuTypeARM = 12,
    MachCpuTypeARM64 = MachCpuTypeARM | MachAbiX64,
    /* RISC-V 64-bit when. Come on Apple, I'm waiting (sarcasm) */
    MachCpuTypeRISCV32 = 24,
};

enum {
    ARM64_SUBTYPE_ARM64_32_V8 = 1,
    ARM64_SUBTYPE_ARM64E = 2,
};

enum {
    MachFileTypeObj = 0,
    MachFileTypePagedExec,
    MachFileTypeFixedVMLib,
    MachFileTypeCoreFile,
    MachFileTypePreloadedExec,
    MachFileTypeDylib,
    MachFileTypeDylinker,
    MachFileTypeBundle,
    MachFileTypeStaticDylibStub,
    MachFileTypeDsym,
    MachFileTypeKextBundle,
    MachFileTypeFileset,
    MachFileTypeGPUExec,
    MachFileTypeGPULibrary,
};

enum {
    MachFlagsNoUndRefs = (1 << 0),
    MachFlagsIncrementalLink = (1 << 1),
    MachFlagsDyldLink = (1 << 2),
    MachFlagsBindAtLoad = (1 << 3),
    MachFlagsPrebound = (1 << 4),
    MachFlagsSplitSges = (1 << 5),
    MachFlagsLazyInit = (1 << 6),
    MachFlagsTwoLevel = (1 << 7),
    MachFlagsForceFlat = (1 << 8),
    MachFlagsNoMultiDefs = (1 << 9),
    MachFlagsNoFixPrebeinding = (1 << 10),
    MachFlagsPrebindable = (1 << 11),
    MachFlagsAllModsBound = (1 << 12),
    MachFlagsSubSectViaSyms = (1 << 13),
    MachFlagsCanonical = (1 << 14),
    MachFlagsWeakDefines = (1 << 15),
    MachFlagsBindsToWeak = (1 << 16),
    MachFlagsAllowStackExec = (1 << 17),
    MachFlagsRootSafe = (1 << 18),
    MachFlagsSetUIDSafe = (1 << 19),
    MachFlagsNoReexportedDylibs = (1 << 20),
    MachFlagsPIE = (1 << 21),
    MachFlagsDeadStrippableDylib = (1 << 22),
    MachFlagsHasTlvDescs = (1 << 23),
    MachFlagsNoHeapExec = (1 << 24),
    MachFlagsAppExtSafe = (1 << 25),
    MachFlagsNListOutOfSyncWithDyldInfo = (1 << 26),
    MachFlagsSimulatorSupport = (1 << 27),
    MachFlagsImplicitPageZero = (1 << 28),
    MachFlagsDylibInCache = (1 << 29),
};

struct {
    uint32_t Command;
    uint32_t CommandSize;
} typedef MachLoadCommand;

typedef enum {
    CmdReqDyld = 0x80000000,

    Segment = 1,
    SymbolTable = 2,
    SymbolSegment = 3,
    Thread = 4,
    UNIXThread = 5,
    LoadFixedVMLib = 6,
    FixedVMLibID = 7,
    ID = 8,
    FixedVMFile = 9,
    PrePage = 10,
    DynamicSymbolTable = 11,
    LoadDylib = 12,
    DylibID = 13,
    LoadDyLinker = 14,
    DyLinkerID = 15,
    PreBoundDylib = 16,
    Routines = 17,
    SubFramework = 18,
    SubUmbrella = 19,
    SubClient = 20,
    SubLibrary = 21,
    TwoLevelHints = 22,
    PrebindChecksum = 23,
    LoadWeakDylib = 24 | CmdReqDyld,
    Segment64 = 25,
    Routines64 = 26,
    UUID = 27,
    RunPath = 28 | CmdReqDyld,
    CodeSignature = 29,
    SegmentSplitInfo = 30,
    ReexportDylib = 31 | CmdReqDyld,
    LazyLoadDylib = 32,
    EncryptionInfo = 33,
    DyldInfo = 34,
    DyldInfoOnly = 34 | CmdReqDyld,
    LoadUpwardDylib = 35 | CmdReqDyld,
    VersionMinMacOS = 36,
    VersionMiniOS = 37,
    FunctionStarts = 38,
    DyldEnvironment = 39,
    Main = 40 | CmdReqDyld,
    DataInCode = 41,
    SourceVersion = 42,
    DylibCodeSignDRs = 43,
    EncryptionInfo64 = 44,
    LinkerOption = 45,
    LinkerOptimizationHint = 46,
    VersionMinTvOS = 47,
    VersionMinWatchOS = 48,
    Note = 49,
    BuildVersion = 50,
    DyldTrieExports = 51 | CmdReqDyld,
    DyldChainedFixups = 52 | CmdReqDyld,
    FilesetEntry = 53 | CmdReqDyld,
    AtomInfo = 54,
} MachCommand;

struct MachSegment32 {
    MachLoadCommand base;
    char SegmentName[16];
    UInt32 VirtualAddress;
    UInt32 VirtualSize;
    UInt32 FileOffset;
    UInt32 FileSize;
    SInt32 MaxProt;
    SInt32 InitialProt;
    UInt32 NumSections;
    UInt32 Flags;
};

struct MachSegment64 {
    MachLoadCommand base;
    char SegmentName[16];
    UInt64 VirtualAddress;
    UInt64 VirtualSize;
    UInt64 FileOffset;
    UInt64 FileSize;
    SInt32 MaxProt;
    SInt32 InitialProt;
    UInt32 NumSections;
    UInt32 Flags;
};

enum {
    MachSegFlagsHighVM = (1 << 0),
    MachSegFlagsFixedVMLib = (1 << 1),
    MachSegFlagsNoReloc = (1 << 2),
    MachSegFlagsProtectedV1 = (1 << 3),
    MachSegFlagsReadOnly = (1 << 4),
};

struct {
    char SectionName[16];
    char SegmentName[16];
    UInt32 Address;
    UInt32 Size;
    UInt32 Offset;
    UInt32 Alignment;
    UInt32 RelocationOffset;
    UInt32 NumRelocations;
    UInt32 Flags;
    UInt32 Rsvd1;
    UInt32 Rsvd2;
} typedef MachSection32;

struct {
    char SectionName[16];
    char SegmentName[16];
    UInt64 Address;
    UInt64 Size;
    UInt32 Offset;
    UInt32 Alignment;
    UInt32 RelocationOffset;
    UInt32 NumRelocations;
    UInt32 Flags;
    UInt32 Rsvd1;
    UInt32 Rsvd2;
    UInt32 Rsvd3;
} typedef MachSection64;

struct {
    MachLoadCommand Base;
    UInt64 VirtualAddress;
    UInt64 FileOffset;
    UInt32 FileIDOffset; /* Not even going to bother with the weird __LP64__ define check. I'll handle the weirdness when it happens. */
    UInt32 Reserved;
} typedef MachFilesetCommand;

#pragma mark Platform FunctionStarts

union {
    MachSection32 Sect32;
    MachSection64 Sect64;
} typedef MachSection;

union {
    UInt32 Magic;
    MachOHeader64 Header64;
    MachOHeader Header32;
} typedef MachHeader;

typedef struct _MachFile *MachFileRef;

#define kMachSectionText "__TEXT"
#define kMachSectionData "__DATA"
