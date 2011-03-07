#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>


int main(void)
{
    int pid;
    
    pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(-1);
    }
    if(pid > 0)
    {
        while(1)
        {
            printf("father\n");
        }
    }
    else
    {
        sleep(2);
        kill(pid, SIGKILL);
    }

    return 0;
}


