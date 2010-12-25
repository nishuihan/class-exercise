#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[5];
    int *p;
    if(a[1]==*(a+1))
        printf("==\n");
    else
        printf("!==\n");
    return 0;
}
