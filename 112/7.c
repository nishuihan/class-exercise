#include <stdio.h>

int main(int argc, const char *argv[])
{
    char aa[2]="1f";
    char bb[2]="11";
    int cc[2];
    int i;
    for (i = 0; i <2; i++) 
    {
       cc[i]=(int)aa[i]+(int)bb[i];
       printf("%c\n",(char)cc[i]);
    }
    printf("%s\n",(char)cc);
    return 0;
}
