#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void printfsigset(const sigset_t *set)
{
    int i;
    for(i=0; i<32; i++)
    {
        if(sigismember(set, i) == 1)
            putchar('1');
        else
            putchar('0');
        puts("");
    }
}

int main(void)
{
    sigset_t s, p;

    sigemptyset(&s);
    sigaddset(&s, SIGINT);
    sigprocmask(SIG_BLOCK, &s, NULL);
    while(1)
    {
        sigpending(&p);
        printfsigset(&p);
        sleep(1);
    }

    return 0;
}





