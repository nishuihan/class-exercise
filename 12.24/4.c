#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct fun {
    char a;
    int b;
} /* optional variable list */;
int main(int argc, const char *argv[])
{
    struct fun *aa;
    int i;
    aa = malloc(sizeof(aa));
    printf("%p\n",malloc(sizeof(aa)));
    if ( aa != NULL)
    {
        for (i = 0; i < 10; i++) 
        {
            aa[i].a = i + 1 + 97;
            aa[i].b = i + 1;
        }
    }
    for (i = 0; i < 10; i++) 
    {
        printf("%c\n", aa[i].a);
        printf("%d\n", aa[i].b);
    }
    return 0;
}
