#include <stdio.h>
char * strcpy(char * dest,const char * sur)
{
    int i;
    for (i = 0; i < sizeof(dest) && sur[i] != '\0'; i++) 
    {
        dest[i] = sur[i];
    }
    for (; i <= sizeof(dest); i++) 
    {
        dest[i] = '\0';
    }
    return dest;
}
char * strcpy1(char * dest,const char * sur)
{
    int i;
    while(dest[i++] = sur[i]);
    return dest;
}
char * strcpy2(char * dest,const char * sur)
{
    char * p = dest;
    while( * p++ = * sur++);
    return dest;
}
char * strcpy3(char * dest,const char * sur)
{
    int i;
    while(sur[i])
    {
        dest[i] = sur[i++];
    }
    dest[i] = '\0';
    return dest;
}
    
int main(int argc, const char *argv[])
{
    char aa[5];
    printf("%s\n",strcpy(aa,"abcd"));
    printf("%s\n",strcpy(aa,"abcdfde"));
    return 0;
}
