#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

static int fib(int n)
{
    if (n < 1)
        return -1;
    else if (n <= 2)
        return (n - 1);

    return fib(n - 1) + fib(n - 2);
}

int sys_find_fibonacci_number(void)
{
    return fib(myproc()->tf->ebx);
}