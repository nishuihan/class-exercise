#include <stdio.h>

int main(int argc, const char *argv[])
{
    int * p[4];
    char a[10] = {1, 4, 3},b;
    char aa[10] = "143";
    p[0] = (int *) a;
    p[1] = (int *) aa;
   b = * (char *)(p[0]);
   printf("%d\n", b);
   printf("%d\n", * ((char *)p[0] + 1));
   printf("%c\n", * (char *)(p[1]));
   printf("%d\n", * ((char *)p[1] + 1));
    return 0;
}
