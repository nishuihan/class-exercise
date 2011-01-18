#include <stdio.h>

int main(int argc, const char *argv[])
{
    int b[10][111];
    int (*p)[111];
    p = b;
    printf("%p\n", p);
    printf("%p\n", &b[0][0]);
    return 0;
}
