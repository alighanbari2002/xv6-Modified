#include "user.h"
#include "types.h"
#include "stat.h"

int main()
{
    sem_init(0, 1, 0); // mutex
    sem_init(1, 5, 0); // empty
    sem_init(2, 5, 5); // full
    int pid = fork();
    if (pid == 0)
    {
        producer(0);
    }
    else
    {
        consumer(0);
        wait();
    }
    wait();
    exit();
}
