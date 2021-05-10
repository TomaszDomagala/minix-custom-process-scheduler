#include <lib.h>
#include <minix/rs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int get_pm_endpt(endpoint_t *pt) { /* so_2021 */
    return minix_rs_lookup("pm", pt);
}

int setbid(int bid) { /* so_2021 */
    endpoint_t pm_pt;
    message m;

    if (bid < 0 || bid > MAX_BID) {
        errno = EINVAL;
        return -1;
    }
    if (get_pm_endpt(&pm_pt) < 0) {
        errno = ENOSYS;
        return -1;
    }
    m.m_lsys_pm_setbid.bid = bid;
    // printf("setbid bid = %d\n", m.m_lsys_pm_setbid.bid);
    return _syscall(pm_pt, PM_SETBID, &m);
}
