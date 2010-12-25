#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    int i;
    for (i = 0; i < argc; i++) 
    {
        printf("atgv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
