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
        if(fun(max,(a + size * i)) >= 0)
        {
        }
        else 
            max = a + size * i;
    }
    return max;
}
int main(int argc, const char *argv[])
{
    int aa[10] = {1,3,4,5,6,3,2,7,8};    
    void * ret;
    ret = get_max(aa,10,4,com_int);
    printf("%d\n",*(int *)ret);
    return 0;
}
