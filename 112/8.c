#include <stdio.h>
#define num  sizeof(aa)
int main(int argc, const char *argv[])
{
    char aa[12];
    //char aa[20];
    char bb[num];
    int i=0,j=0,n=0;
    gets(aa);
   while(aa[j]!=' ')
    {
       j++;
    }
   //n=j;
    //printf("%d\n",n);
    //printf("%d\n",num);
    for (i = 0; i < j; i++) 
    {
        bb[i]=aa[i];
        aa[i]=aa[j+1+i];
    }
    for (i = j+1; i <(num-1); i++) 
    {
        aa[i]=bb[i-j-1];
    }
    printf("%s\n",aa);
    return 0;
}
