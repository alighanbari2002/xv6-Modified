#include "x86.h"
#include "spinlock.h"

void initlock(struct spinlock *lk)
{
    lk->locked = 0;
}

void lock(struct spinlock *lk)
{
    while (xchg(&lk->locked, 1) != 0)
        ;
}

void unlock(struct spinlock *lk)
{
    asm volatile("movl $0, %0"
                 : "+m"(lk->locked)
                 :);
}
