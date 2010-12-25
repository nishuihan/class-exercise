#include <stdio.h>

int main(int argc, const char *argv[])
{
    int * p[4],a = 10;
    int  b[10] = {1,2,3,4,56};
    char c[10] = "123";
    char cc[10] = {97,98,99};
    p[1] = &cc[0];
    p[0] = &a;
    printf("%p %x\n",&p[0], &a);
    printf("%p\n",&p[1]);
    //printf("%c\n",*(p[1]));
    //printf("%c\n",**(p+1));
    //printf("%d\n",*(( char *)p[1]+1));
    //printf("%d\n",*(char *)(*(p+1) + 1));
    return 0;
}
