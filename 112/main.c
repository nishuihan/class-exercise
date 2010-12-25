#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0,j='A';
    for (i = 0; i < 64; i++) 
    {
        printf("(%-3d,%c)\t",j,j);
        j++;
        if((i+1)%5==0)
        {
          putchar('\n');
        }
    }
    return 0;
}
