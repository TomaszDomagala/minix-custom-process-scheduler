#include <lib.h>
#include <minix/rs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* so_2021 */
int get_pm_endpt(endpoint_t *pt) { return minix_rs_lookup("pm", pt); }

/* so_2021 */
int setbid(int bid) {
    endpoint_t pm_pt;
    message m;

    // TODO add MAX_BID constant variable
    if (bid < 0 || bid > 100) {
        errno = EINVAL;
        return -1;
    }
    if (get_pm_endpt(&pm_pt) < 0) {
        errno = ENOSYS;
        return -1;
    }
    m.m_setbid.bid = bid;
    if (_syscall(pm_pt, PM_SETBID, &m) < 0) {
        errno = ENOSYS;
        return -1;
    }

    return m.m_setbid.bid;
}