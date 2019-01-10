/*
 * Copyright 2018 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <command.h>
#include <common.h>
#include <malloc.h>
#include <environment.h>
#include <linux/types.h>
#include "test.h"

void core1_main(void)
{
	test_i2c();
	test_irq_init();
	test_gpio();
	test_icc_func_init();
	test_qspi();

	return;
}


void core2_main(void)
{
	test_icc_func_init();

	return;
}

void core3_main(void)
{
	test_icc_func_init();

	return;
}
