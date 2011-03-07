#include <stdio.h>
#include <signal.h> 

void handler(int num)
{
    printf("%d \n", num);
}

int main(void)
{
    int pid;
    struct sigaction act;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    
    sigaction(SIGINT, &act, 0);
    if((pid = fork()) < 0 )
    {
        perror("fork");
        exit(1);
    }
    if(pid == 0)
    {
        printf("child\n");
        kill(pid, SIGINT);
    }
    if(pid > 0)
    {
        pause();
        printf("father\n");
        //printf("father again\n");
    }

    return 0;
}

        

