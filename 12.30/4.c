#include <stdio.h>

int mul(int a, int b)
{
    int i, num = 0, count = 0;
    for (i = 0; i < 32; i++) 
    {
        num = ((b >> i) & 1) ? (a << i) : 0 ;
        count += num;
    }
    return count;
}
int main(int argc, const char *argv[])
{
    printf("%d\n", mul(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
