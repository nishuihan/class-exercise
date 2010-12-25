#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    char *a;
    int i;
    a = (char *)malloc(10);
    if (a != NULL)
    {
        for (i = 0; i < 10; i++) 
        {
            a[i] = i + 1;
        }
        for (i = 0; i < 10; i++) 
        {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}
