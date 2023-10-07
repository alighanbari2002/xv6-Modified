#include "types.h"
#include "stat.h"
#include "user.h"

#define HIGH 100000


int main()
{
    if(!fork())
    {
        calc(HIGH);
        exit();
    }
    else if(!fork())
    {
        calc(HIGH);
        exit();
    }
    else
    {
        calc(HIGH);
        while(wait() != -1);
    }
    exit();
}