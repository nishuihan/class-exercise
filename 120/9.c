#include <stdio.h>
void swap(int *,int *);
int main(int argc, const char *argv[])
{
    int i=10,j=20;
    swap(&i,&j);
    printf("%d,%d\n",i,j);
    return 0;
}
void swap(int *a,int *b)
{
   int temp;
    temp=*a;
    *a=*b;
    *b= temp;
}
   
