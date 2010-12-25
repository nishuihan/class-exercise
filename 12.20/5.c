#include <stdio.h>
#include <string.h>
union day{
    int a;
    char ss[20];
};
union day day1; 
int main(int argc, const char *argv[])
{
    day1.a=121;
    printf("%x\n",&day1.ss[0]);
    printf("%x\n",&day1.ss[1]);
    strcpy(day1.ss,"abc");
    printf("%d\n",day1.a);
    printf("%s\n",day1.ss);
    return 0;
}
