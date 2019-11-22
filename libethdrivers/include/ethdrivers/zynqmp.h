/*
 * Copyright 2017, DornerWorks, Ltd.
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(OTHER_GPL)
 */

#ifndef __ETHIF_ZYNQMP_DRIVER_H
#define __ETHIF_ZYNQMP_DRIVER_H

#include <platsupport/io.h>
#include <ethdrivers/raw.h>

#define ZYNQMP_INTERRUPT_GEM3 95

/**
 * This function initialises the hardware and conforms to the ethif_driver_init
 * type in raw.h
 * @param[out] eth_driver   Ethernet driver structure to fill out
 * @param[in] io_ops        A structure containing os specific data and
 *                          functions.
 * @param[in] config        Platform Specific configuration data
 */
int ethif_zynqmp_init(struct eth_driver *eth_driver, ps_io_ops_t io_ops, void *config);

#endif
