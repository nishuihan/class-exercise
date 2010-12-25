#include <stdio.h>
int printf_line(int k)
{
    int i;
    for (i = 0; i < k; i++) 
    {
        printf("*");
    }
    return 0;
}
int  printf_matrix(int a)
{
     int i;
     int (* fun1)(int);
     fun1=printf_line;
     for (i = 0; i < a; i++) 
     {
           (*  fun1)(4);
           printf("\n");
     }
     return 0;
}
int main(int argc, const char *argv[])
{
    int (* fun)(int);
    fun=printf_matrix;
    (* fun)(4);
    return 0;
}
