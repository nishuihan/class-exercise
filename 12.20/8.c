#include <stdio.h>
int printf_line(void)
{
    printf(" * ");
    return 0;
}
int printf_matic(int (* fun_t)(void))
{
    int i = 0,j = 0;
    for (i = 0; i < 6; i++) 
    {
          for (j = 0; j < 6; j++) 
          {
              fun_t();
          }
          printf("\n");
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    
    printf_matic(printf_line);
    return 0;
}
