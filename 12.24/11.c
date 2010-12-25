#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i , j = 0;
    int a[10];
    for (i = 0; i < 10; i++) 
    {
        scanf("%d",&a[i]);
        //getchar();
        if (a[i] == -1) 
        {
            break;
        }
    }
    j = i;
    for (i = 0; i < j; i++) 
    {
        printf("%d", a[i]);
    }
    return 0;
}
