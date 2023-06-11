#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define READERS_SEM 0
#define WRITERS_SEM 1
#define MAX_BUF 100
#define TEST_FILE "some_read.txt"
#define PRINT_STR "A warm Welcome From me!\n"

int main()
{
    // sem_init(READERS_SEM, 3); 
    // sem_init(WRITERS_SEM, 2);
    
    unlink(TEST_FILE);
    int fd = open(TEST_FILE, O_RDWR | O_CREATE);
    if(fd < 0)
    {
        printf(1, "not open\n");
    }
    write(fd, PRINT_STR, 24);
    char buf[MAX_BUF];
    memset(buf, 0, MAX_BUF);
    read(fd, buf, MAX_BUF);
    printf(1, "file: %s", buf);

    // for(int i = 0; i < 5; i++)
    // {
    //     int pid = fork();
    //     if(pid < 0)
    //     {
    //         printf(1, "error on creating child!\n");
    //     }
    //     if(pid > 0)
    //     {
    //         // printf(1, "pid is: %d\n", pid);
    //         continue;
    //     }
    //     else // pid == 0
    //     {
    //         if(i == 1 || i == 2 || i == 4) // readers
    //         {
    //             sem_acquire(READERS_SEM);
    //             char buf[MAX_BUF];
    //             memset(buf, 0, MAX_BUF);
    //             read(fd, buf, MAX_BUF);
    //             printf(1, "file: %s", buf);
    //             sem_release(READERS_SEM);
    //             exit();
    //         }
    //         else if(i == 0 || i == 3) // 0 & 4 writers
    //         {
    //             // sem_acquire(READERS_SEM);
    //             // sem_acquire(READERS_SEM);
    //             // sem_acquire(READERS_SEM);

    //             // sem_acquire(WRITERS_SEM);
    
                
    //             // sem_release(WRITERS_SEM);
                
    //             // sem_release(READERS_SEM);
    //             // sem_release(READERS_SEM);
    //             // sem_release(READERS_SEM);

    //             exit();
    //         }
    //     }
    // }
    // close(fd);
    // for(int i = 0; i < 5; i++)
    // {
    //     wait();
    // }
    close(fd);
    exit();
}