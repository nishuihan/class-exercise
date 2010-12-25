#include <stdio.h>
#define N 10
struct people {
    int id;
    int out;
};
struct people a[N];
int main(int argc, const char *argv[])
{
    int i,n = 0,j = 0;
    for (i = 0; i < N; i++) 
    {
        a[i].id = i + 1;
        a[i].out = 0;
    }
    for (i = 0; i < 10; i++) 
    {
        for(;;)
        {
            if (a[n].out == 0) 
                j++;
            if (j == 3) 
            {
                j = 0;
                a[n].out = 1;
                printf("%d\n", n + 1);
                break;
            }
            n++;
            n = n % 10;
        }
    }
        for (i = 0; i < 10; i++) 
        {
           if (a[i].out == 0) 
           {
               printf("%d\n",a[i].id);
            }
        }
    
    return 0;
}
