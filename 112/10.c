#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    char  a[]="12"; 
    char b[]="1b"; 
    b[0]+=a[0]-'0';
    b[1]+=a[1]-'0';
    printf("%c\n",b[0]);
    printf("%c\n",b[1]);
    printf("%s\n",b);
    return 0;
}
