#include <stdio.h>

int main(void)
{
    int i = 0;
    int pid[3];
    int n = 0;
    int m = 1;

    pid[0] = fork();
    if(pid[0] == 0 )
    {
        n++;
        printf("%d ", n);
        printf("son\n");
    }
    else
        for(i=1; i<2; i++)
        {
            if(pid[i] > 0)
            {
                pid[i - 1] = fork();
                if(pid[i - 1] == 0)
                {
                    m++;
                    printf("%d ", m);
                    printf("son\n");
                }
                //printf("%d \n", i);
            }
        }

    return 0;
}
