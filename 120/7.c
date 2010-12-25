#include <stdio.h>

int main(int argc, const char *argv[])
{
    char *p;
    char aa[5];
    printf("%p\n",aa);
    p=aa;
    printf("%p\n",aa);
    printf("%p\n",p);
    scanf("%s",p);
    //printf("%s\n",aa);
    printf("%p\n",&aa[1]);
    printf("%p\n",aa);
    printf("%p\n",p);
    printf("%p\n",p+1);
    printf("%c\n",*(p+1));
    return 0;
}
