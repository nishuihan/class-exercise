#include <stdio.h>
int foo(void)
{
    int i = 0;
    {
        int i = 1;
        int j = 2;
        printf("i = %d,j = %d\n",i,j);
    }
    printf("i = %d\n",i);
    return 0;
}
int main(int argc, const char *argv[])
{
    foo();    
    return 0;
}
