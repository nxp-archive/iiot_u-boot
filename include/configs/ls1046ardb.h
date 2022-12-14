/*
 * Copyright 2016 Freescale Semiconductor
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __LS1046ARDB_H__
#define __LS1046ARDB_H__

#include "ls1046a_common.h"
#include "ls1046ardb_config.h"

#define CONFIG_ICC

#define CONFIG_MASTER_CORE                     0

#define CONFIG_SYS_DDR_SDRAM_SHARE_BASE \
	(CONFIG_SYS_DDR_SDRAM_BASE + CONFIG_SYS_DDR_SDRAM_MASTER_SIZE \
	+ CONFIG_SYS_DDR_SDRAM_SLAVE_SIZE * (CONFIG_MAX_CPUS - 1))

#define CONFIG_SYS_DDR_SDRAM_SHARE_RESERVE_BASE \
	(CONFIG_SYS_DDR_SDRAM_SHARE_BASE + CONFIG_SYS_DDR_SDRAM_SHARE_SIZE)

#ifdef CONFIG_SD_BOOT
#define CONFIG_SYS_TEXT_BASE		0x82000000
#endif

#define CONFIG_SYS_CLK_FREQ		100000000
#define CONFIG_DDR_CLK_FREQ		100000000

#define CONFIG_LAYERSCAPE_NS_ACCESS
#define CONFIG_MISC_INIT_R

#define CONFIG_DIMM_SLOTS_PER_CTLR	1
/* Physical Memory Map */
#define CONFIG_CHIP_SELECTS_PER_CTRL	4
#define CONFIG_NR_DRAM_BANKS		2

#define CONFIG_DDR_SPD
#define SPD_EEPROM_ADDRESS		0x51
#define CONFIG_SYS_SPD_BUS_NUM		0

#define CONFIG_DDR_ECC
#define CONFIG_ECC_INIT_VIA_DDRCONTROLLER
#define CONFIG_MEM_INIT_VALUE           0xdeadbeef
#define CONFIG_FSL_DDR_BIST	/* enable built-in memory test */
#ifndef CONFIG_SPL
#define CONFIG_FSL_DDR_INTERACTIVE	/* Interactive debugging */
#endif

#ifdef CONFIG_RAMBOOT_PBL
#define CONFIG_SYS_FSL_PBL_PBI board/freescale/ls1046ardb/ls1046ardb_pbi.cfg
#endif

#ifdef CONFIG_SD_BOOT
#ifdef CONFIG_EMMC_BOOT
#define CONFIG_SYS_FSL_PBL_RCW \
	board/freescale/ls1046ardb/ls1046ardb_rcw_emmc.cfg
#else
#define CONFIG_SYS_FSL_PBL_RCW board/freescale/ls1046ardb/ls1046ardb_rcw_sd.cfg
#endif
#endif

#ifndef SPL_NO_IFC
/* IFC */
#define CONFIG_FSL_IFC
/*
 * NAND Flash Definitions
 */
#define CONFIG_NAND_FSL_IFC
#endif

#define CONFIG_SYS_NAND_BASE		0x7e800000
#define CONFIG_SYS_NAND_BASE_PHYS	CONFIG_SYS_NAND_BASE

#define CONFIG_SYS_NAND_CSPR_EXT	(0x0)
#define CONFIG_SYS_NAND_CSPR	(CSPR_PHYS_ADDR(CONFIG_SYS_NAND_BASE_PHYS) \
				| CSPR_PORT_SIZE_8	\
				| CSPR_MSEL_NAND	\
				| CSPR_V)
#define CONFIG_SYS_NAND_AMASK	IFC_AMASK(64 * 1024)
#define CONFIG_SYS_NAND_CSOR	(CSOR_NAND_ECC_ENC_EN	/* ECC on encode */ \
				| CSOR_NAND_ECC_DEC_EN	/* ECC on decode */ \
				| CSOR_NAND_ECC_MODE_8	/* 8-bit ECC */ \
				| CSOR_NAND_RAL_3	/* RAL = 3 Bytes */ \
				| CSOR_NAND_PGS_4K	/* Page Size = 4K */ \
				| CSOR_NAND_SPRZ_224	/* Spare size = 224 */ \
				| CSOR_NAND_PB(64))	/* 64 Pages Per Block */

#define CONFIG_SYS_NAND_ONFI_DETECTION

#define CONFIG_SYS_NAND_FTIM0		(FTIM0_NAND_TCCST(0x7) | \
					FTIM0_NAND_TWP(0x18)   | \
					FTIM0_NAND_TWCHT(0x7) | \
					FTIM0_NAND_TWH(0xa))
#define CONFIG_SYS_NAND_FTIM1		(FTIM1_NAND_TADLE(0x32) | \
					FTIM1_NAND_TWBE(0x39)  | \
					FTIM1_NAND_TRR(0xe)   | \
					FTIM1_NAND_TRP(0x18))
#define CONFIG_SYS_NAND_FTIM2		(FTIM2_NAND_TRAD(0xf) | \
					FTIM2_NAND_TREH(0xa) | \
					FTIM2_NAND_TWHRE(0x1e))
#define CONFIG_SYS_NAND_FTIM3		0x0

#define CONFIG_SYS_NAND_BASE_LIST	{ CONFIG_SYS_NAND_BASE }
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_MTD_NAND_VERIFY_WRITE
#define CONFIG_CMD_NAND

#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)

/*
 * CPLD
 */
#define CONFIG_SYS_CPLD_BASE		0x7fb00000
#define CPLD_BASE_PHYS			CONFIG_SYS_CPLD_BASE

#define CONFIG_SYS_CPLD_CSPR_EXT	(0x0)
#define CONFIG_SYS_CPLD_CSPR		(CSPR_PHYS_ADDR(CPLD_BASE_PHYS) | \
					CSPR_PORT_SIZE_8 | \
					CSPR_MSEL_GPCM | \
					CSPR_V)
#define CONFIG_SYS_CPLD_AMASK		IFC_AMASK(64 * 1024)
#define CONFIG_SYS_CPLD_CSOR		CSOR_NOR_ADM_SHIFT(16)

/* CPLD Timing parameters for IFC GPCM */
#define CONFIG_SYS_CPLD_FTIM0		(FTIM0_GPCM_TACSE(0x0e) | \
					FTIM0_GPCM_TEADC(0x0e) | \
					FTIM0_GPCM_TEAHC(0x0e))
#define CONFIG_SYS_CPLD_FTIM1		(FTIM1_GPCM_TACO(0xff) | \
					FTIM1_GPCM_TRAD(0x3f))
#define CONFIG_SYS_CPLD_FTIM2		(FTIM2_GPCM_TCS(0xf) | \
					FTIM2_GPCM_TCH(0xf) | \
					FTIM2_GPCM_TWP(0x3E))
#define CONFIG_SYS_CPLD_FTIM3		0x0

/* IFC Timing Params */
#define CONFIG_SYS_CSPR0_EXT		CONFIG_SYS_NAND_CSPR_EXT
#define CONFIG_SYS_CSPR0		CONFIG_SYS_NAND_CSPR
#define CONFIG_SYS_AMASK0		CONFIG_SYS_NAND_AMASK
#define CONFIG_SYS_CSOR0		CONFIG_SYS_NAND_CSOR
#define CONFIG_SYS_CS0_FTIM0		CONFIG_SYS_NAND_FTIM0
#define CONFIG_SYS_CS0_FTIM1		CONFIG_SYS_NAND_FTIM1
#define CONFIG_SYS_CS0_FTIM2		CONFIG_SYS_NAND_FTIM2
#define CONFIG_SYS_CS0_FTIM3		CONFIG_SYS_NAND_FTIM3

#define CONFIG_SYS_CSPR2_EXT		CONFIG_SYS_CPLD_CSPR_EXT
#define CONFIG_SYS_CSPR2		CONFIG_SYS_CPLD_CSPR
#define CONFIG_SYS_AMASK2		CONFIG_SYS_CPLD_AMASK
#define CONFIG_SYS_CSOR2		CONFIG_SYS_CPLD_CSOR
#define CONFIG_SYS_CS2_FTIM0		CONFIG_SYS_CPLD_FTIM0
#define CONFIG_SYS_CS2_FTIM1		CONFIG_SYS_CPLD_FTIM1
#define CONFIG_SYS_CS2_FTIM2		CONFIG_SYS_CPLD_FTIM2
#define CONFIG_SYS_CS2_FTIM3		CONFIG_SYS_CPLD_FTIM3

/* EEPROM */
#define CONFIG_ID_EEPROM
#define CONFIG_SYS_I2C_EEPROM_NXID
#define CONFIG_SYS_EEPROM_BUS_NUM		0
#define CONFIG_SYS_I2C_EEPROM_ADDR		0x53
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		1
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	3
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	5
#define I2C_RETIMER_ADDR			0x18

/* PMIC */
#define CONFIG_POWER
#ifdef CONFIG_POWER
#define CONFIG_POWER_I2C
#endif

/*
 * Environment
 */
#ifndef SPL_NO_ENV
#define CONFIG_ENV_OVERWRITE
#endif

#if defined(CONFIG_SD_BOOT)
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_ENV_OFFSET		(3 * 1024 * 1024)
#define CONFIG_ENV_SIZE			0x2000
#else
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_SIZE			0x2000		/* 8KB */
#define CONFIG_ENV_OFFSET		0x300000	/* 3MB */
#define CONFIG_ENV_SECT_SIZE		0x40000		/* 256KB */
#endif

#define AQR105_IRQ_MASK			0x80000000
/* FMan */
#ifndef SPL_NO_FMAN

#ifdef CONFIG_NET
#define CONFIG_PHYLIB
#define CONFIG_PHY_GIGE		/* Include GbE speed/duplex detection */
#define CONFIG_PHY_REALTEK
#endif

#ifdef CONFIG_SYS_DPAA_FMAN
#define CONFIG_FMAN_ENET
#define CONFIG_PHY_AQUANTIA
#define CONFIG_PHYLIB_10G
#define RGMII_PHY1_ADDR			0x1
#define RGMII_PHY2_ADDR			0x2

#define SGMII_PHY1_ADDR			0x3
#define SGMII_PHY2_ADDR			0x4

#define FM1_10GEC1_PHY_ADDR		0x0

#define CONFIG_ETHPRIME			"FM1@DTSEC3"
#endif

#endif

/* QSPI device */
#ifndef SPL_NO_QSPI
#ifdef CONFIG_FSL_QSPI
#define CONFIG_SPI_FLASH_SPANSION
#define FSL_QSPI_FLASH_SIZE		(1 << 26)
#define FSL_QSPI_FLASH_NUM		2
#endif
#endif

/*
 * GPIO
 */
#define CONFIG_MPC85XX_GPIO
#define CONFIG_DM_GPIO
#define SHARED_GPIO_REQUEST_INFO

/* USB */
#ifndef SPL_NO_USB
#define CONFIG_HAS_FSL_XHCI_USB
#ifdef CONFIG_HAS_FSL_XHCI_USB
#define CONFIG_USB_XHCI_HCD
#define CONFIG_USB_XHCI_FSL
#define CONFIG_USB_XHCI_DWC3
#define CONFIG_USB_MAX_CONTROLLER_COUNT		1
#define CONFIG_USB_STORAGE
#endif
#endif

/* SATA */
#ifndef SPL_NO_SATA
#define CONFIG_LIBATA
#define CONFIG_SCSI_AHCI
#define CONFIG_SCSI_AHCI_PLAT
#define CONFIG_SCSI

#define CONFIG_SYS_SATA				AHCI_BASE_ADDR

#define CONFIG_SYS_SCSI_MAX_SCSI_ID		1
#define CONFIG_SYS_SCSI_MAX_LUN			1
#define CONFIG_SYS_SCSI_MAX_DEVICE		(CONFIG_SYS_SCSI_MAX_SCSI_ID * \
						CONFIG_SYS_SCSI_MAX_LUN)
#endif

#ifndef SPL_NO_MISC
#undef CONFIG_BOOTCOMMAND
#if defined(CONFIG_QSPI_BOOT)
#define CONFIG_BOOTCOMMAND "run distro_bootcmd; run qspi_bootcmd; "     \
			   "env exists secureboot && esbc_halt;"
#elif defined(CONFIG_SD_BOOT)
#define CONFIG_BOOTCOMMAND "run distro_bootcmd; run sd_bootcmd; "       \
			   "env exists secureboot && esbc_halt;"
#endif

#define MTDPARTS_DEFAULT "mtdparts=1550000.quadspi:1m(rcw)," \
			"15m(u-boot),48m(kernel.itb);" \
			"7e800000.flash:16m(nand_uboot)," \
			"48m(nand_kernel),448m(nand_free)"
#endif

#define CONFIG_ENABLE_COREID_DEBUG
#define CONFIG_ENABLE_WRITE_LOCK

#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS		\
			"ipaddr=192.168.1.1\0" \
			"eth1addr=00:04:9F:04:F0:F1\0" \
			"eth2addr=00:1F:7B:63:35:E9\0" \
			"eth3addr=00:04:9F:04:F0:F3\0" \
			"eth4addr=00:04:9F:04:F0:F4\0" \
			"eth5addr=00:04:9F:04:F0:F5\0" \
			"eth6addr=00:04:9F:04:F0:F6\0" \
			"eth7addr=68:05:ca:35:cc:61\0" \
			"ethact=FM1@DTSEC3\0"			\

#include <asm/fsl_secure_boot.h>

#endif /* __LS1046ARDB_H__ */
