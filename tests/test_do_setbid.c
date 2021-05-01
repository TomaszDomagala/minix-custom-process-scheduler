#include <assert.h>
#include <lib.h>
#include <minix/rs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  message m;
  endpoint_t pm_ep;
  minix_rs_lookup("pm", &pm_ep);

  int n = 2;
  m.m_setbid.bid = 2;
  int res = _syscall(pm_ep, PM_SETBID, &m);

  assert(res == 0);
  assert(m.m_setbid.bid == 2 * n);
  printf("Test passed!\n");
}