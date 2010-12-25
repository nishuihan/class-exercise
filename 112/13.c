#include <stdio.h>
#define num  sizeof(aa)
int main(int argc, const char *argv[])
{
    char aa[]="hello world";
    char bb[num];
    int i;
    for (i = 0; i < 5; i++) 
    {
        bb[i]=aa[i];
        aa[i]=aa[6+i];
    }
    for (i = 6; i <(num-1); i++) 
    {
        aa[i]=bb[i-6];
    }
    printf("%s\n",aa);
    return 0;
}
