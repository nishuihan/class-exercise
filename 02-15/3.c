#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deal_poke()
{
    int poke[54] = {
                    11, 12, 13, 14, 15, 16, 17, 18, 19, 110, 111, 112, 113,
                    21, 22, 23, 24, 25, 26, 27, 28, 29, 220, 211, 212, 213,
                    31, 32, 33, 34, 34, 36, 37, 38, 39, 310, 311, 312, 313, 
                    41, 42, 43, 44, 45, 46, 47, 48, 49, 410, 411, 412, 413, 
                    50, 51};
    int a[4][14];
    int mark[54];
    int num = 0, i = 0, j = 14, n = 4, count;
    
    srand(time(NULL));
    while(i<54)
    {
        num = rand() % 55;
        if(i > 0)
        {
            while(count--)
            {
                if(mark[count] == num)
                    mark[count] = num = rand() % 55;
            }
        }
        mark[i] = num;
        i++;
        count = i - 1;
    }
    while(i--)
        printf("%d ", mark[i]);
    printf("\n");
    #if 1
    for(j=0; j<14; j++)
        for(n=0; n<4; n++)
        {
            a[n][j] = poke[mark[i]];
        }

     printf("%d\n", poke[48]);
     #endif
}
int main(int argc, char *argv[])
{
    deal_poke();
    return 0;
}
