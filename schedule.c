#include "types.h"
#include "user.h"

void set_tickets(int pid, int tickets)
{
    if (pid < 1)
    {
        printf(1, "Invalid pid\n");
        return;
    }
    if (tickets < 0)
    {
        printf(1, "Invalid tickets\n");
        return;
    }
    int res = set_lottery_ticket(pid, tickets);
    if (res < 0)
        printf(1, "Error setting tickets\n");
    else
        printf(1, "Tickets set successfully\n");
}

int main(int argc, char *argv[])
{
}