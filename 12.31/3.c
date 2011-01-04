#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fun(char *x)
{
    char * p  = malloc(100);
    x = p;
    strcpy(p, "abc");
    //x = p;
    printf("%s\n", p);
    printf("%s\n", x);
}
void fun1(char **x)
{
    char * p  = malloc(100);
    *x = p;
    strcpy(p, "abc");
    //x = p;
    printf("%s\n", p);
    printf("%s\n", *x);
}
int main(int argc, const char *argv[])
{
    char *q = "ddd";
    //fun(q);
    //printf("%s\n", q);
    fun1(&q);
    printf("%s\n", q);

    return 0;
}
