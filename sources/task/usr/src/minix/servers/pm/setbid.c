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

/* so_2021 */
int do_setbid(void) {
    int bid = m_in.m_setbid.bid;
    mp->mp_reply.m_setbid.bid = 2 * bid;

    return OK;
}