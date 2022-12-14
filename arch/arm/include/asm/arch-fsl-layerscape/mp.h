/*
 * Copyright 2014-2015, Freescale Semiconductor
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _FSL_LAYERSCAPE_MP_H
#define _FSL_LAYERSCAPE_MP_H

/*
* Each spin table element is defined as
* struct {
*      uint64_t entry_addr;
*      uint64_t status;
*      uint64_t lpid;
*      uint64_t os_arch;
* };
* we pad this struct to 64 bytes so each entry is in its own cacheline
* the actual spin table is an array of these structures
*/
#define SPIN_TABLE_ELEM_ENTRY_ADDR_IDX	0
#define SPIN_TABLE_ELEM_STATUS_IDX	1
#define SPIN_TABLE_ELEM_LPID_IDX	2
#define SPIN_TABLE_ELEM_OS_ARCH_IDX	3
#define WORDS_PER_SPIN_TABLE_ENTRY	8	/* pad to 64 bytes */
#define SPIN_TABLE_ELEM_SIZE		64

#define id_to_core(x)	((x & 3) | (x >> 6))
#ifndef __ASSEMBLY__
extern u64 __spin_table[];
extern u64 __real_cntfrq;
extern u64 *secondary_boot_code;
extern size_t __secondary_boot_code_size;
#ifdef CONFIG_MP
int fsl_layerscape_wake_seconday_cores(void);
#else
static inline int fsl_layerscape_wake_seconday_cores(void) { return 0; }
#endif
void *get_spin_tbl_addr(void);
phys_addr_t determine_mp_bootpg(void);
void secondary_boot_func(void);
int is_core_online(u64 cpu_id);
u32 cpu_pos_mask(void);
int get_core_id(void);
int is_core_valid(unsigned int core);
#endif

#define IH_ARCH_ARM		2	/* ARM */
#define IH_ARCH_ARM64		22	/* ARM64 */

#endif /* _FSL_LAYERSCAPE_MP_H */
