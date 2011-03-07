#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *fun1(void *p)
{
    
    pthread_mutex_lock(&lock);
    printf("fun 1 lock success\n");
    sleep(3);
    //pthread_mutex_unlock(&lock);
}

void *fun2(void *p)
{
    printf("dddd\n");
    sleep(2);
    //pthread_mutex_unlock(&lock);
    printf("fun2 unlock success\n");
    pthread_mutex_lock(&lock);
    printf("fun2 lock success\n");

}

int main(void)
{
    pthread_t pid, cid;

    pthread_create(&pid,NULL, fun1, NULL);
    pthread_create(&cid, NULL, fun2, NULL);
    sleep(10);
    printf("main suceess\n");
    
    return 0;
}

