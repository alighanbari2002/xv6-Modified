#include "types.h"
#include "stat.h"
#include "user.h"



int main(int argc, char* argv[])
{
    char first = *(argv[1]);
    if((strcmp(argv[1], "print") == 0 && argc == 2) ||
        (strcmp(argv[1], "ticket") == 0 && argc == 4) ||
        (strcmp(argv[1], "change") == 0 && argc == 4))
    {
        switch((int)(first))
        {
            case (int)('p'):
                printProc();
                break;
            case (int)('t'):
                initTicket(atoi(argv[2]), atoi(argv[3]));
                break;
            case (int)('c'):
                changeQueue(atoi(argv[2]), atoi(argv[3]));
                break;
            default:
                printf(1, "unknown\n");
                return 0;
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