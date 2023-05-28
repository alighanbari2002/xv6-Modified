#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int sys_fork(void)
{
  return fork();
}

int sys_exit(void)
{
  exit();
  return 0; // not reached
}

int sys_wait(void)
{
  return wait();
}

int sys_kill(void)
{
  int pid;

  if (argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int sys_getpid(void)
{
  return myproc()->pid;
}

int sys_sbrk(void)
{
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

int sys_sleep(void)
{
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (myproc()->killed)
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_find_most_callee(void)
{
  return find_most_callee();
}

int sys_get_alive_children_count(void)
{
  int pid = myproc()->pid; // parent process
  return get_alive_children_count(pid);
}

int sys_kill_first_child_process(void)
{
  int pid = myproc()->pid; // parent process
  return kill_first_child_process(pid);
}

int sys_set_lottery_ticket(void)
{
  int pid, tickets;
  if (argint(0, &pid) < 0 || argint(1, &tickets) < 0)
    return -1;

  if (tickets < 0)
    return -1;

  return set_lottery_ticket(pid, tickets);
}

int sys_print_proc_info(void)
{
  print_proc_info();
  return 0;
}

int sys_change_sched_queue(void)
{
  int pid, qnum;
  if (argint(0, &pid) < 0 || argint(1, &qnum) < 0)
    return -1;

  if (qnum < ROUND_ROBIN || qnum > FCFS)
    return -1;
  return change_sched_queue(pid, qnum);
}

void sys_sem_init(void)
{
  int i, v, m;
  if (argint(0, &i) < 0)
    return;
  if (argint(1, &v) < 0)
    return;
  if (argint(2, &m) < 0)
    return;
  sem_init(i, v, m);
  return;
}

void sys_sem_acquire(void)
{
  int i;
  if (argint(0, &i) < 0)
    return;
  sem_acquire(i);
  return;
}

void sys_sem_release(void)
{
  int i;
  if (argint(0, &i) < 0)
    return;
  sem_release(i);
  return;
}

void sys_producer(void)
{
  int i;
  if (argint(0, &i) < 0)
    return;
  producer(i);
}

void sys_consumer(void)
{
  int i;
  if (argint(0, &i) < 0)
    return;
  consumer(i);
}

void sys_cv_wait(void)
{
  struct condvar *c;
  if (argptr(0, (void *)&c, sizeof(c)) < 0)
    return;
  cv_wait(c);
}

void sys_cv_signal(void)
{
  struct condvar *c;
  if (argptr(0, (void *)&c, sizeof(c)) < 0)
    return;
  cv_signal(c);
}

void sys_reader(void)
{
  struct condvar *condvar;
  int i;
  if (argint(0, &i) < 0)
    return;
  if (argptr(1, (void *)&condvar, sizeof(condvar)) < 0)
    return;
  reader(i, condvar);
}

void sys_writer(void)
{
  struct condvar *condvar;
  int i;
  if (argint(0, &i) < 0)
    return;
  if (argptr(1, (void *)&condvar, sizeof(condvar)) < 0)
    return;
  writer(i, condvar);
}