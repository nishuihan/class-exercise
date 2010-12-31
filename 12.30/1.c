#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a = 1;
    char b = 2;
    a ^= b;
    a ^= b;
    b ^= a;
    printf("a = %d\n", a);
    printf("%d\n", a^(b^a));
    return 0;
}
