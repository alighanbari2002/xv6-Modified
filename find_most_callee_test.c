#include "types.h"
#include "user.h"
#include "syscall.h"
#include "fcntl.h"

int main()
{
    sleep(1);
    sleep(1);
    sleep(1);
    sleep(1);
    sleep(1);
    sleep(1);
    sleep(1);
    // we call 7 times sleep() that has no 13 in syscall.h
    int max_used_sys_call = find_most_callee();
    printf(1, "\nmost called system call is: %d\n", max_used_sys_call);
    exit();
    return 0;
}