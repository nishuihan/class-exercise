#include <stdio.h>
#define N 10
struct people {
    int id;
    int out;
};
struct people a[N];
int main(int argc, const char *argv[])
{
    int i,n = 0,j = 1,num = 0;
    for (i = 0; i < N; i++) 
    {
        a[i].id = i + 1;
        a[i].out = 0;
    }
    while(n < N - 1)
    {
        while(1)
        {
            if (a[num].out == 0) 
                 j++;
            if (j == 3) 
            {
                a[num].out = 1;
                j = 1;
                printf("%d\n",num);
                break;
            }
            num++;
            num = num % N;
        }
        n++;
    }
    for (i = 0; i < N; i++) 
    {
        if (a[i].out == 0) 
        {
            printf("%d\n",a[i].id);
        }
    }
    return 0;
}
