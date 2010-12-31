#include <stdio.h>
#include <string.h>
char encrypt(char a)
{
    char b = '&';
    a = a ^ b;
    a = a ^ b;
    if (a > ' ' && a < '~')
        printf("%c\n", a);
    else
        printf("this char is no-look, it's ASICC is: %d\n", a);
    return 0;
}
void exchange(char *str)
{
    int i = 0;
    for (i = 0; i < strlen(str); i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
            continue;
        }
        if (str[i] >= 'a' && str[i] <='z')
            str[i] = str[i] + 32;
    }
}
int main(int argc, const char *argv[])
{
    char a, str[10];
     scanf("%c", &a);
    encrypt(a);
        //printf("%c\n", encrypt(a));
    //scanf("%s", str);
    //exchange(str);
    //printf("%s\n", str);
    return 0;
}
