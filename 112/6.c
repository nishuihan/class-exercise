#include <stdio.h>

int main(int argc, const char *argv[])
{
    char aa[2]="12";
    char bb[2]="11";
    char  cc[2];
    int i;
    for (i = 0; i <2; i++) 
    {
        //aa[i]+=bb[i]-'0';
        //aa[i]=aa[i]+'0';
        //printf("%d\n",aa[i]);
        //bb[i]=bb[i]+'0';
        //printf("%d\n",bb[i]);
        cc[i]=aa[i]+bb[i]-'0';
        printf("%c\n",aa[i]);
    }
    printf("%s\n",cc);
    return 0;
}
