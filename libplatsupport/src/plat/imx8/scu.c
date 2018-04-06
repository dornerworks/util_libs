/*
 * Copyright 2018, DornerWorks
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_DORNERWORKS_BSD)
 */
#include <platsupport/plat/sci/sci.h>

void initSCU(void)
{
    sc_ipc_t ipcHndl = 0;
    sc_err_t sciErr = 0;

    global_scu.ipc_channel_handle = 0;
    sciErr = sc_ipc_open(&ipcHndl, SC_IPC_CH);
    if (sciErr != SC_ERR_NONE)
    {
        ZF_LOGE("SC OPEN ERROR: %u\n", sciErr);
    }
    global_scu.ipc_channel_handle = ipcHndl;

    sc_pm_clock_rate_t rate;
    sciErr = sc_pm_get_clock_rate(global_scu.ipc_channel_handle,
                                  SC_R_GPT_0, SC_PM_CLK_PER,
                                  &rate);
    if (sciErr != SC_ERR_NONE)
    {
        ZF_LOGE("Error getting clock rate: %u\n", sciErr);
    }

}
