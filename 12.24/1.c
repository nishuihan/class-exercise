#include <stdio.h>
struct  info_t{
    char sa;
};
int main(int argc, const char *argv[])
{
   struct info_t * aa;
   int *p;
   char a[2];
   p = a;
   printf("%d\n",sizeof(aa));
   printf("%p\n", a);

    return 0;
}
