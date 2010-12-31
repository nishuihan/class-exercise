#include <stdio.h>
#include <string.h>
#define len 32
int get_bit(int a, int l)
{
    return (a>>l) & 1;
}
int mul(int a, int b)
{
    int i, num = 0, count = 0;
    for (i = 0; i < 32; i++) 
    {
        num = ((b >> i) & 1) ? (a << i) : 0 ;
        count += num;
    }
    return count;
}
char * exchange(char *str)
{
    int i = 0;
    for (i = 0; i < strlen(str); i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
            continue;
        }
        if (str[i] >= 'A' && str[i] <='Z')
            str[i] = str[i] + 32;
    }
    return str;
}
char encrypt(char a)
{
    char b = '&';
    a = a ^ b;
    a = a ^ b;
    if (a >= ' ' && a <= '~')
        printf("The code is :%c\n", a);
    else
        printf("This char is invisible, it's ASICC is: %d\n", a);
    return 0;
}
void display(void)
{
    printf("1.Decimal to binary\n");
    printf("2.x * y\n");
    printf("3.Low or up exchange\n");
    printf("4.Encryption\n");
    printf("5.Exit\n");
    printf("Please choose [1 - 5] : ");
}

int main(int argc, const char *argv[])
{
    int num = 0, i = 0, k = 0, x = 0, y = 0, flag = 0;    
    char aa, a;
    char str[100];
    while(1)
    {
        display();
        scanf("%d", &num);
        switch(num)
        {
            case 1:
                printf("Input a number: ");
                scanf("%d", &k);
                getchar();
                for (i = 0; i < len; i++) 
                {
                    printf("%d ", get_bit(k, len - i - 1));
                }
                printf("\n");
                break;
            case 2:
                printf("Please input x y: ");
                scanf("%d %d", &x, &y);
                printf("%d * %d = %d\n", x, y, mul(x, y));
                getchar();
                break;
            case 3:
                printf("Please input a string: ");
                scanf("%s", str);
                getchar();
                printf("%s\n", exchange(str));
                break;
            case 4:
                printf("Please input a char: ");
                //scanf("%c", &aa);
                //getchar();
                getchar();
                encrypt((aa = getchar()));
                getchar();
                break;
            case 5:
                return 0;
                //default:
                ////printf("Please input number 1 - 5\n");
        }
        getchar();
        //while((a = getchar()) != '\n');
    }
    return 0;

}
