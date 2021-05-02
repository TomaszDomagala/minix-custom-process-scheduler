#include <assert.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/sched.h>
#include <minix/vm.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/wait.h>

#include "mproc.h"
#include "pm.h"


int do_setbid(void) { /* so_2021 */
    message m;

    /* If the kernel is the scheduler, we don't allow messing with the
     * priority. If you want to control process priority, assign the process
     * to a user-space scheduler */
    if (mp->mp_scheduler == KERNEL || mp->mp_scheduler == NONE) return (EINVAL);

    m.m_pm_sched_setbid.bid = m_in.m_lsys_pm_setbid.bid;
    m.m_pm_sched_setbid.endpoint = mp->mp_endpoint;

    int res = _taskcall(mp->mp_scheduler, SCHEDULING_SETBID, &m);
    if(res != 0){
        return res;
    }
    
    return OK;
}