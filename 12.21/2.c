#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    int i = 0, j = 0;
    int t;
    int a[10] = {3,4,29,22,11,2,8,9,21,20};
    for (j = 0; j < 9; j++) 
        for (i = 0; i < 9 - j; i++) 
        {
            if (a[i] > a[i + 1]) 
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
     for (i = 0; i < 10; i++) 
     {
         printf("%d\n",a[i]);
     }
    return 0;
}
