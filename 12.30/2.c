#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 9;
    int b = -9;
    int i;
    for (i = 0; i < 32; i++) 
    {
        printf("%d ", a & 1);
        a >>= 1;
    }
    printf("\n");
    for (i = 0; i < 32; i++) 
    {
        printf("%d ", b & 1);
        b >>= 1;
    }
    printf("\n");
    return 0;
}
