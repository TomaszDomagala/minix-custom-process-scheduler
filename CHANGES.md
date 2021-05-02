#modified files:
/usr/src/minix/include/minix/callnr.h oraz /usr/include/minix/callnr.h - PM_SETBID
/usr/src/minix/inclide/minix/com.h oraz /usr/include/minix/com.h - SCHEDULING_SETBID
/usr/src/minix/inclide/minix/ipc.h oraz /usr/include/minix/ipc.h - mess_setbid
/usr/src/include/unistd.h oraz /usr/include/unistd.h - setbid declaration


Flow:
- libc setbid(bid) sends mess_slib_pm_setbid message to pm server with bid value.
- pm server sends mess_pm_sched_setbid to sched server with bid value and process's endpoint (int do_setbid(void)).
- 