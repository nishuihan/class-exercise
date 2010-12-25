#include <stdio.h>
#include <string.h>
struct count{
    int num;
    int m;
};
struct count cnt[100];
int temp, temp1;
void get_max(char * a)
{
    int i, j = 0, c, n = 1;
    for (i = 0; i < strlen(a); i++) 
    {
        if ( a[i] == a[i + 1])
        {
            n++;
        }
        if( a[i] != a[i + 1])
        {
            cnt[j].num = n;
            cnt[j].m = i - n + 1;
            j++;
            n = 1;
        }
    }
    temp = cnt[0].num;
    for(i=0;i<j-1;i++)
    {
        if(cnt[i+1].num>cnt[i].num)
            temp = cnt[i+1].num;
            temp1 = i + 1;
    }
    printf("%d\n",temp);
}
int main(int argc, const char *argv[])
{
    int i;
    char str[] = "abbbccdddddddadffffffffffffffff"; 
    get_max(str);
    for (i = 0; i < temp; i++) 
    {
        printf("%c",str[cnt[temp1].m]);
    }
    printf("\n");
    return 0;
}
