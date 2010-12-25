#include <stdio.h>
int strlen1(char * s)
{
    int i = 0;
    while(s[i++]);
    return i; 
}
int strlen2(char * s)
{
    for (int i = 0; s[i] != 0; i++);
    return i;
}
int main(int argc, const char *argv[])
{
    printf("%d\n", strlen1("hello"));
    printf("%d\n", strlen2("hello"));
    return 0;
}
