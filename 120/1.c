#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a;
    a=getchar();
    while(a!='\0')
    {
        putchar(a);
        a=getchar();
    }
    return 0;
}
