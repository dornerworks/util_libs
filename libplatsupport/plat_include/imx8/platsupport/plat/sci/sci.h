/*
 * Copyright (C) 2016 Freescale Semiconductor, Inc.
 * Copyright 2017 NXP
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

/*==========================================================================*/
/*!
 * @file sci.h
 *
 * Header file containing the public System Controller Interface (SCI)
 * definitions.
 *
 *
 * @{
 */
/*==========================================================================*/

#ifndef _SC_SCI_H
#define _SC_SCI_H

/* Defines */
#define SCU_PADDR           0x30000000
#define MU_BASE_PADDR       0x5D1B0000
#define MU_BASE_ADDR(id)    ((MU_BASE_PADDR + (id*0x1000)))

/* Includes */

#include <platsupport/plat/sci/types.h>
#include <platsupport/plat/sci/ipc.h>
#include <platsupport/plat/sci/svc/misc/api.h>
#include <platsupport/plat/sci/svc/otp/api.h>
#include <platsupport/plat/sci/svc/pad/api.h>
#include <platsupport/plat/sci/svc/pm/api.h>
#include <platsupport/plat/sci/svc/rm/api.h>
#include <platsupport/plat/sci/svc/timer/api.h>
#include <utils/zf_log.h>

#define SC_IPC_AP_CH0       	(MU_BASE_ADDR(0))
#define SC_IPC_AP_CH1       	(MU_BASE_ADDR(1))
#define SC_IPC_AP_CH2       	(MU_BASE_ADDR(2))
#define SC_IPC_AP_CH3       	(MU_BASE_ADDR(3))
#define SC_IPC_AP_CH4       	(MU_BASE_ADDR(4))

#define SC_IPC_CH		SC_IPC_AP_CH0

/* Types */
typedef struct scu{
    seL4_Word ipc_channel_handle;
}scu_t;

static scu_t global_scu;

/* Functions */
void initSCU(void);

#endif /* _SC_SCI_H */

/**@}*/
