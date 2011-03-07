#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock[5];
int sum = 40;

void *fun(void *p)
{
    int n = *(int *)p;//you cannot send the pointer

    while(1)
    {
        sleep(1);
        if(n == 1)
        {
            if(sum==0)
            {
                printf("eatting finished\n");
                break;
                //exit(1);
            }
            pthread_mutex_lock(&lock[4]);
            printf("the P1 get the chopstick 5 \n");
            pthread_mutex_lock(&lock[0]);
            printf("the P1 get the chopstick 1 \n");
            sum--;

            usleep(rand() % 10);

            pthread_mutex_unlock(&lock[4]);
            pthread_mutex_unlock(&lock[0]);
            printf("the P1 release the chopstick 5 and 1 \n");
            if(sum==0)
            {
                printf("eatting finished\n");
                break;
                exit(1); 
            }
        }
        else
        {
            if(sum==0)
            {
                printf("eatting finished\n");
                break;
                //exit(1); 
            }

            pthread_mutex_lock(&lock[n-2]);
            printf("the P%d get the chopstick %d \n",n, n - 1);
            pthread_mutex_lock(&lock[n-1]);
            printf("the P%d get the chopstick %d \n",n, n);
            sum--;

            usleep(rand() % 10);

            pthread_mutex_unlock(&lock[n-2]);
            pthread_mutex_unlock(&lock[n-1]);
            printf("the P%d release the chopstick %d  %d \n",n, n - 1, n);
            if(sum==0)
            {
                printf("eatting finished\n");
                break;
                exit(1); 
            }
        }
        usleep(rand() % 10);

    }

}

int main(void)
{
    pthread_t tid[5];
    int n;

    srand(time(NULL));
    for(n=0; n<5; n++)
        pthread_mutex_init(&lock[n], NULL);

    for(n=1; n<6; n++)
    {
        pthread_create(&tid[n - 1], NULL, fun, &n);
    }
    for(n=1; n<6; n++)
    {
        pthread_join(tid[n - 1], NULL);
    }

    return 0;
}
