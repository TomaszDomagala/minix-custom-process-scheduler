#include <assert.h>
#include <lib.h>
#include <minix/rs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int n = 2;
  int res = setbid(n);

  assert(res == 2 * n);
  printf("Test passed!\n");
}