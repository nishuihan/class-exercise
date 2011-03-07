#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flag;

void guess_game(int num, int tmp)
{
    int i = 0, j = 0, count = 0;
    int aa[4] = {0};
    int bb[4] = {0};
    char str[4] = "0000";

    aa[0] = num / 1000;
    aa[1] = num %1000 / 100;
    aa[2] = num %100 / 10;
    aa[3] = num % 10;

    bb[0] = tmp / 1000;
    bb[1] = tmp %1000 / 100;
    bb[2] = tmp %100 / 10;
    bb[3] = tmp % 10;

    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            if(bb[i] == aa[i])
            {
                printf("A");
                str[count] = 'A';
                count++;
                break;
            }
            else if(bb[i] == aa[j] && i != j)
            {
                printf("B");
                str[count] = 'B';
                count++;
                break;
            }
        }

    if(str[0] == 'A' && str[1] == 'A' && str[2] == 'A' && str[3] == 'A')
        flag = 1;

    printf("\n");
}
    
int main(int argc, char *argv[])
{
    int num = 0, tmp = 0;

    srand(time(NULL));
    num = rand() % 10000;
    printf("%d\n", num);

    while(1)
    {
        printf("Please input the number(the number is between 1000 and 9999): ");
        scanf("%d", &tmp);
        while(tmp % 1111 == 0)
        {
            printf("the number is wrong! Please input again: ");
            scanf("%d", &tmp);
        }
        guess_game(num, tmp);
        if(flag == 1)
        {
            flag = 0;
            printf("You are sucess,Please receive the new challage\n");
            num = rand() % 10000;
            printf("%d\n", num);
        }
    }

    return 0;
}
