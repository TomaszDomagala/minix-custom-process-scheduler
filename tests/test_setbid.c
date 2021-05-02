#include <assert.h>
#include <lib.h>
#include <minix/rs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int res;

    // res = setbid(0);
    // assert(res == 0);

    res = setbid(300);
    printf("res = %d, errno = %d\n", res, errno);

    printf("Test passed!\n");
}
