#include "user.h"
#include "types.h"
#include "stat.h"
#include "spinlock.h"

struct condvar
{
    struct spinlock lock;
};

int main()
{
    struct condvar c;

    int pid = fork();
    if (pid < 0)
    {
        printf(2, "Error forking child!\n");
    }
    else if (pid == 0)
    {
        int pid1 = fork();
        if (pid1 == 0)
        {
            int pid1 = fork();
            if (pid1 == 0)
            {
                writer(1, &c);
            }
            else
            {
                reader(2, &c);
                wait();
            }
        }
        else
        {
            reader(1, &c);
            wait();
        }
    }
    else
    {
        int pid1 = fork();

        if (pid1 == 0)
        {
            writer(0, &c);
        }
        else
        {
            reader(0, &c);
            wait();
        }
        wait();
    }
    exit();
    return 0;
}
