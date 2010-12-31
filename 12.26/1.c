#include <stdio.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    char a[234] = "hello";
    char b[234] = {0};
    strcpy(b, a + 1);
    printf("%s\n", b);
    strcpy(a, b);
    printf("%s\n", a);
    return 0;
}
