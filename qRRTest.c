#include "types.h"
#include "stat.h"
#include "user.h"



int main()
{
    int pid = fork();
    char* argv[] = {"qRRTest2", 0};
    if(pid == 0)
    {
        exec("./qRRTest2", argv);
        printf(1, "exec failed!\n");
        exit();
    }
    for(uint i = 0; i < 99999999; i++)
    {
    }
    wait();
    exit();
}