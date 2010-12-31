#include <stdio.h>
int summation(char *format, ...)
{
    int *a, sum = 0, i = 0;
    for (a = (int *)&format, a++; i < 3 ; a++, i++) 
        sum = sum + *a;
    return sum;
}
int main(int argc, const char *argv[])
{
    printf("%d\n", summation(" ", 1, 2, 3));
    return 0;
}
