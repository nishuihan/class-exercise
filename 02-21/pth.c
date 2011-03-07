#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem[5];

void *fun(void *p)
{
    int *n;

    n = (int *)p;
    sleep(rand() % 3);

    sem_wait(&sem[*n - 1]);
    if(*n == 1)
    {
        printf("the P1 get the chopstick 5 \n");
    }
    else
    {
        printf("the P%d get the chopstick %d \n",*n, *n);
    }
    sem_post(&sem[*n - 1]);

    sem_wait(&sem[*n]);
    if(*n == 1)
    {
        printf("the P1 get the chopstick 1 \n");
    }
    else
    {
        printf("the P%d get the chopstick %d \n",*n, *n + 1);
    }

    sem_post(&sem[*n]);
}
    
int main(void)
{
    pthread_t tid[5];
    int n = 0;

    for(n=0; n<5; n++)
    {
        sem_init(&sem[n], 0, 1);
    }

    while(1)
    {
        for(n=1; n<6; n++)
        {
            pthread_create(&tid[n - 1], NULL, fun, &n);
        }
        for(n=0; n<6; n++)
        {
            pthread_join(tid[n], NULL);
        }
    }

    return 0;
}
