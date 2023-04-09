#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"

int main()
{
    int child = fork();
    if (child > 0) // parent
    {
        printf(1, "Number of alive childs before killing: %d\n", get_alive_children_count());
        int is_successful = kill_first_child_process();
        if (is_successful)
        {
            printf(1, "Number of alive childs after killing: %d\n", get_alive_children_count());
        }
        else
        {
            printf(2, "parent has no child.");
        }
    }
    else if (child == 0) // child
    {
        while (1)
        { // don't die until your parent kills you!
        }
    }
    else
    {
        printf(2, "fork failed.");
    }

    while (wait() != -1)
    { // wait for all children to die,
    } // otherwise they will become zombies.
    sleep(1);

    exit();
    return 0;
}