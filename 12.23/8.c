#include <stdio.h>
#include <string.h>
#define N 100
int temp = 0, temp1;
void get_max(char * a)
{
    int i, n = 1;
    for (i = 0; i < strlen(a); i++) 
    {
        if ( a[i] == a[i + 1])
        {
            n++;
        }
        if( a[i] != a[i + 1])
        {
            if (n > temp)
            {
                temp =n;
                temp1 = i - n + 1;
            }
            n = 1;
        }
    }
    printf("%d\n",temp);
}
int main(int argc, const char *argv[])
{
    int i;
    char c;
    //char str[] = "abbbcc"; 
    char str[N];
    //for (i = 0;i < n && str[i - 1]!= '\n';i++)
    //{
        //scanf("%c",&str[i]);// inpuing character by wto mathods
    //}
    scanf("%s",str);
    get_max(str);
    for (i = 0; i < temp; i++) 
    {
        printf("%c",str[temp1]);
    }
    printf("\n");
    return 0;
}
