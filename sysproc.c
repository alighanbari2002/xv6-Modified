#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
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
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

void
sys_printProc(void)
{
  // since ptable is only accessible in proc.c
  // we need yet another wrapper or
  // could've used extern keyword
  printProc();
}

int
sys_changeQueue(void)
{
  int pid;
  int queueID;
  if(argint(0, &pid) < 0 ||
    argint(1, &queueID) < 0 ||
    (/*queueID != DEF &&*/
    queueID != RR &&
    queueID != LOTTERY &&
    queueID != FCFS))
  {
    return -1;
  }
  changeQueue(pid, queueID);
  return 0;
}

int
sys_initTicket(void)
{
  int pid;
  uint ticket;
  if(argint(0, &pid) < 0 ||
    argint(1, (int*)(&ticket)) < 0 ||
    ticket > 100)
  {
    return -1;
  }
  initTicket(pid, ticket);
  return 0;
}