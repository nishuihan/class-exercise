#include <stdio.h>
void myprintf(char *format, ...)
{
    char *p;
    p = (char *)&format;
    p = p + 4;
    printf("%s\n", (char *)(int *)p);//this is must "int *"
}
void myprintf1(char *format, ...)
{
    int *p;
    p = (int *)&format;
    p = p + 1;
    printf("%s\n", (char *)*p);
}
void myprintf2(char *format, ...)
{
    char *p;
    int i;
    p = (char *)&format;
    for (i = 1; i < 4; i++) 
    {
        p = p + 4;
        printf("%s\n", (char *)*(int *)p);
    }
}
int main(int argc, const char *argv[])
{
    
    myprintf2(" " , "how", "are", "you");
    myprintf1(" " , "hello world");
    return 0;
}
