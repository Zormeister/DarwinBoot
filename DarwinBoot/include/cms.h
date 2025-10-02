// Copyright (C) 2025 Samuel Zormeister, All rights reserved. Licensed under the BSD-3 Clause License.

#ifndef __CMS_H__
#define __CMS_H__

#include <CoreDarwinBoot/CDBBasicTypes.h>
#include <stdio.h>

__BEGIN_DECLS

/*!
 * @group Core Memory Services
 *
 * CMS is a wrapper for the platform layer of memory management, enabling runtime tracking of memory.
 */

#if DEBUG || DEVELOPMENT
#define __cms_allow_diagnostics__ 1
#else
#define __cms_allow_diagnostics__ 1
#endif

#if UEFI
#define __cms_assume_physical__ 1
#else
#define __cms_assume_physical__ 0
#endif

typedef enum {
    cms_state_uninitialised = 0,
    cms_state_active,
    cms_state_deactivated,
} cms_state_t;

struct {
    void *(*calloc)(size_t count, size_t size);
    void *(*malloc)(size_t size);
    void *(*realloc)(size_t size);
    void (*free)(void *ptr);
} typedef cms_callbacks_t;

typedef enum {
    cms_memory_region_dontcare = 0,

    cms_memory_region_kernel, /* kernel or kernelcache */
    cms_memory_region_bootargs, /* the boot args structure that's placed into memory prior to jumping to xnu */
    cms_memory_region_devicetree, /* the region the devicetree binary is stored in */
    cms_memory_region_ramdisk, /* region of memory the root ramdisk is stored in */
    cms_memory_region_bootlogos, /* region where the FailedCLUT + other pictures are stored */

    cms_memory_region_kext_dungeon,

    cms_memory_region_max,
} cms_memory_region_t;

typedef struct _cms_memory_desc_s *cms_memory_desc_t;

bool cms_initialize(const cms_callbacks_t *callbacks);

void *cms_allocate_memory_multiple(size_t cnt, size_t size);
void *cms_allocate_memory(size_t size);
void *cms_reallocate_memory(void *orig, size_t size);
void cms_free_memory(void *memory);

void *cms_allocate_region(cms_memory_region_t region, size_t size);

/* this api call should only remove non-region marked allocations. i wouldn't want to free the kernel binary. */
void cms_shutdown(void);

cms_state_t cms_get_current_state(void);

cms_memory_desc_t cms_get_desc_by_address(physical_address_t phys, virtual_address_t virt);

physical_address_t cms_memory_desc_get_physical_address(cms_memory_desc_t);
virtual_address_t cms_memory_desc_get_virtual_address(cms_memory_desc_t);
size_t cms_memory_desc_get_size(cms_memory_desc_t);

#if __cms_allow_diagnostics__
void cms_diagnostic_dump(void);
#endif

__END_DECLS

#endif /* __CMS_H__ */
