#include <stdio.h>
void set_zero(int *p);
int main(int argc, const char *argv[])
{
    int i=10;
    set_zero(&i);
    printf("%d\n",i);
    return 0;
}
void set_zero(int *p)
{
    *p=0; 
}

