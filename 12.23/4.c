#include <stdio.h>
int strlen(const char * s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
int main(int argc, const char *argv[])
{
    char aaa[10];
    int i;
    char a[10] = "hello";
    char aa[10];
    for (i = 0; i < 10; i++) 
    {
    printf("%d\n",aaa[i]);
    }
    printf("%d\n",strlen(aa));

    return 0;
}
