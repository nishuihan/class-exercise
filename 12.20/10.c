#include <stdio.h>
int com_int(void * a,void * b)
{
    return *(int *)a - * (int *)b;
}
int com_char(void * a,void * b)
{
    return *(char *)a - * (char *)b;
}
void * get_max(void * a,int len,int size,int (* fun)(void *,void *))
{
    void * max;
    int i = 0;
    max = a;
    for (i = 0; i < len - 1; i++) 
    {
        if( fun(max,(a + size * i)) >= 0)
        {
            max = max;
        }
        else 
            max = a + size * i;
    }
    return max;
}
int main(int argc, const char *argv[])
{
    int aa[10] = {1,3,4,5,6,3,2,7,8};    
    char bb[10] = {12,23,23,44,22,11,56};
    void * ret, * ret1;
    ret = get_max(aa,10,4,com_int);
    ret1 = get_max(bb,10,1,com_char);
    printf("%d\n",*(int *)ret);
    printf("%d\n",*(int *)ret1);
    return 0;
}
