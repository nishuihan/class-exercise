#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=0;
    float j=3.14f;
    //char aa[ ]="abc";
    char aa[]={'a','\0','b','c'};
    //printf("0x%x\n",&aa[0]);
    //printf("iii0x%d\n",aa);
    //printf("0x%x\n",aa);
    //printf("%d\n",sizeof j);
    //while(1);
    printf("%s\n",aa);
    while(1);
    for (i = 0; i < 5; i++) 
    {
        putchar(aa[i]);
        putchar(' ');
        printf("%d\n",aa[i]);
        printf("0x%x\n",&aa[i]);
        //printf("%d,%d\n",sizeof aa,sizeof aa[i]);
      //  printf("%c\n",aa[i]);
    }
    //while(i<3)
    //{
    //putchar(aa[i]);
    //i++;
    //}
    //for(i=0;i<3;i++);
        //printf("%d\n",i);
    return 0;
}
