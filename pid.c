#include "types.h"
#include "user.h"
#include "fcntl.h"

int main()
{
    int pid = getpid();
    printf(1, "%d\n",  pid);
    exit();
}