#include "types.h"
struct stat;
struct rtcdate;
struct condvar;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int *);
int write(int, const void *, int);
int read(int, void *, int);
int close(int);
int kill(int);
int exec(char *, char **);
int open(const char *, int);
int mknod(const char *, short, short);
int unlink(const char *);
int fstat(int fd, struct stat *);
int link(const char *, const char *);
int mkdir(const char *);
int chdir(const char *);
int dup(int);
int getpid(void);
char *sbrk(int);
int sleep(int);
int uptime(void);
int find_fibonacci_number(void);
int find_most_callee(void);
int get_alive_children_count(void);
int kill_first_child_process(void);
int set_lottery_ticket(int, int);
int change_sched_queue(int, int);
void print_proc_info(void);
void sem_init(int, int, int);
void sem_acquire(int);
void sem_release(int);
void producer(int);
void consumer(int);
void cv_wait(struct condvar *);
void cv_signal(struct condvar *);
void reader(int, struct condvar *);
void writer(int, struct condvar *);

// ulib.c
int stat(const char *, struct stat *);
char *strcpy(char *, const char *);
void *memmove(void *, const void *, int);
char *strchr(const char *, char c);
int strcmp(const char *, const char *);
void printf(int, const char *, ...);
char *gets(char *, int max);
uint strlen(const char *);
void *memset(void *, int, uint);
void *malloc(uint);
void free(void *);
int atoi(const char *);
