#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char *argv[])
{
    char *a;
    int i;
    a = (char *)malloc(10);
    printf("%p\n", a);
    if (a != NULL)
    {
        for (i = 0; i < 10; i++) 
        {
            *(a++) = i + 1;
            printf("%p\n", a);
        }
        
        for (i = 0; i >-10 ; i--) 
        {
            //printf("%d\n", a[i]);
            printf("%d\n", *(a--));
            printf("%p\n", a);
        }
    }
    return 0;
}
