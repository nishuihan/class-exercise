#include <stdio.h>
int compare_int(void * a,void * b)
{
    if(* (int *)a > * (int *)b)
        return 1;
    else
        return 0;
}
int compare_char(void * a,void * b)
{
    if( * (char *)a > * (char *)b)
        return 1;
    else
        return 0;
}
void * get_max(void * a,int length,int size,int (* fun)(void,void))
{
    void * max_p;
    max_p = a;
    length = strlen(a);
    for (i = 0; i <length *a) ; i++) 
    {
       if (fun(* (a + i),* (a + i  + 1)))
          
    }
int main(int argc, const char *argv[])
{
    
    return 0;
}
