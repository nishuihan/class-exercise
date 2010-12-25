#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    char aa[]={'a','\0','b','c'};
    printf("%s\n",aa);//THe difference of string and char 
    for (i = 0; i < 4; i++) 
    {
        putchar(aa[i]);
        putchar(' ');
        printf("%d\n",aa[i]);
    }
    return 0;
}
