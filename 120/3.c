#include <stdio.h>

int main(int argc, const char *argv[])
{
    int *p;
    int i=0;
    double  j=1;
    double  *p1;
    long double k=0;
    p=&i;
    p1=&j;
    printf("0x%x\n",p);
    printf("0x%x\n",p+1);
    printf("0x%x\n",p+2);
    printf("0x%x\n",p1);
    printf("%d\n",sizeof(k));
    printf("%d\n",sizeof(j));
    printf("%d\n",sizeof(p));
    printf("0x%x\n",p1+1);
    printf("0x%x\n",p1+2);
    return 0;
}
