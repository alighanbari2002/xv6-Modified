#include "types.h"
#include "fcntl.h"
#include "user.h"
#include "syscall.h"

int main(int argc, char *argv[])
{
    int c1 = fork();
    int c2 = fork();
    int c3 = fork();

    if (c1 > 0 && c2 > 0 && c3 > 0) // parent
    {
        printf(1, "Number of alive childs: %d\n", get_alive_children_count());
    }

    while (wait() != -1)
    { // wait for all children to die,
    } // otherwise they will be zombies.

    sleep(1);
    exit();
    return 0;
}
