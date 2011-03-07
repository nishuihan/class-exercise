#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int num = 0, i = 13, j = 13;
    
    srand(time(NULL));
    while(i--)
    {
        num = rand() % 14;
        printf("%d ", num);
    }
    printf("\n");
    while(j--)
    {
        num = rand() % 14;
        printf("%d ", num);
    }
    printf("\n");

    return 0;
}

