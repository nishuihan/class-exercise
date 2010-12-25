#include <stdio.h>
void printf_star(void)
{
    printf("*");
}
int main(int argc, const char *argv[])
{
    int (* fun)(void);
    int n=argv[1][0]-48,i=0,j=0;//there is a "./a/out" in argv[0][0]
    fun = printf_star;
    for (i = 0; i < n; i++,putchar('\n')) 
    {
        for (j = 0; j < n; j++) 
        {
            (* fun)();
        }
    }
    return 0;
}
