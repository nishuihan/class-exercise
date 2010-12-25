// count the number of spaces and enters
#include <stdio.h>
int main(int argc, const char *argv[])
{
    int i=0,j=0;
    char aa=getchar();
    while(aa!='q')
    {
        if(aa==' ')
            ++i;
        if(aa=='\n')
            ++j;
        aa=getchar();        
    }
    printf("%d %d\n",i,j);
    return 0;
}
