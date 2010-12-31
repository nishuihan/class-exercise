#include <stdio.h>
int get_bit(int a, int len)
{
    return (a>>len) & 1;
}
int main(int argc, const char *argv[])
{
    
    int i, len = 32;
    int c = 9;
    for (i = 0; i < len; i++) 
    {
        printf("%d ", get_bit(c, len - i - 1));
    }
    printf("\n");
    return 0;
}
