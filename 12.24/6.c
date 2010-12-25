#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int *p;
    int i = 0, j = 0;
    p = (int *)malloc(2);
    for (i = 0;  *(p + i - 1) != -1; i++) 
    {
       scanf("%d",p + i); 
       if(i == 10)
            p = (int *)realloc(p, 4);
    }
    j = i;
    for (i = 0; i < j; i++) 
    {
        printf("%d  ", p[i]);
    }
    printf("\n");
    return 0;
}
