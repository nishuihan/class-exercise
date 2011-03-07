#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

pthread_t ntid;

void printids(char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    //tid = pthread_self();
    //printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
    printids(arg);
    
    return NULL;
}

int main(int argc, char *argv[])
{
    int err;
    
    err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
    if(err != 0)
    {
        perror("pthread_creat");
        exit(1);
    }
    printids("main thread: ");
    sleep(1);

    return 0;
}

