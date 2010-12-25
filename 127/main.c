#include <stdio.h>
int i=97;
int main(int argc, const char *argv[])
{
    
    printf("int:%d\n",i); // 0x%d\n,&i
    printf("char:%c\n",i);
    printf("0x%x\n",&i);
    return 0;
}
