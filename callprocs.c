#include "types.h"
#include "stat.h"
#include "user.h"



int main(int argc, char* argv[])
{
    if((strcmp(argv[1], "print") == 0 && argc == 2) ||
        (strcmp(argv[1], "ticket") == 0 && argc == 4) ||
        (strcmp(argv[1], "change") == 0 && argc == 4))
    {
        switch((int)(*argv[1]))
        {
            case 'p':
                print_proc();
                break;
            case 't':
                init_ticket(atoi(argv[2]), atoi(argv[3]));
                break;
            case 'c':
                change_queue(atoi(argv[2]), atoi(argv[3]));
                break;
        }
    }
    else
    {
        printf(1, "bad argument. use one of the following:\n\
print: usage: callprocs print\n\
ticket: usage: callprocs ticket [pid] [ticket]\n\
change: usage: callprocs change [pid] [queue]\n");
    }
    exit();    
}