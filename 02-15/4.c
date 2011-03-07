#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deal_poke()
{
    int a[4][13];
    int b[54] = {0};
    char c[4] = {'b', 'r', 'm', 'f'};
    int num = 0, i = 0, j = 0, color = 0, mark = 0;

    srand(time(NULL));
    for(i=0; i<13; i++)
        for(j=0; j<4; j++)
        {
            num = rand() % 54;
            if(b[num] == 0)
            {
                a[j][i] = num;
                b[num] = 1;
            }
            else
                while(1)
                {
                    num = rand() %54;
                    if(b[num] == 0)
                    {
                        a[j][i] = num;
                        b[num] = 1;
                        break;
                    }
                }
        }
    for(j=0; j<4; j++)
    {
        for(i=0; i<13; i++)
        {
            color = a[j][i] / 13;
            mark = a[j][i] % 13 + 1;
            if(color > 3 && mark == 1)
            {
                printf("dw  ");
                continue;
            }
            if(color > 3 && mark == 2)
            {
                printf("xw  ");
                continue;
            }
            printf("%c%-2d ", c[color], mark);
        }
        printf("\n");
    }
}
                
int main(int argc, const char *argv[])
{
    
    deal_poke();
    return 0;
}
