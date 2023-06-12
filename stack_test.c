#include "types.h"
#include "stat.h"
#include "user.h"



void
rec_func(long long int i)
{
    if(i > 10000)
    {
        return;
    }
    rec_func(i+1);
    print_stack_top();
}

int main()
{
    rec_func(0);
    exit();
}