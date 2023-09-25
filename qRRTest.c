#include "types.h"
#include "stat.h"
#include "user.h"



int main()
{
    int pid = fork();
    if(pid == 0)
    {
        for(uint i = 0; i < 99999999; i++)
        {
            for(uint j = 0; j < 9999; j++)
            {
            }
        }
        exit();
    }
    for(uint i = 0; i < 99999999; i++)
    {
        for(uint j = 0; j < 9999; j++)
        {
        }
    }
    wait();
    exit();
}