#include <stdio.h>
#include <string.h>
struct count{
    int num;
    int m;
};
struct count cnt[100];
void get_max(char * a, int (* fun)(char *, char *))
{
    int i, j, c, n;
    for (i = 0; i < strlen(a); i++) 
    {
        if ( !fun(a[i],a[i + 1]))
        {
            n++;
            c++;
        }
        if( fun(a[i],a[i + 1]))
        {
            cnt[j].num = n;
            cnt[j].m = c;
            j++;
        }
    }
}
int main(int argc, const char *argv[])
{
    int i;
    char str[10] = "abbbccdddd"; 
    get_max(str,str_camp);
    for (i = 0; i <strlen(cnt); i++) 
    {
        printf("%d\n",cnt[i].num);
        printf("%d\n",cnt[i].m);
    }
    return 0;
}
