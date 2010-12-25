#include <stdio.h>
int main(int argc, const char *argv[])
{
    char a[6]="abcde";
    int *p;
    int i=0;
    for (i = 0; i < 5; i++) 
    {
        printf("%c\n",*(a+i));
    }
    return 0;
}
