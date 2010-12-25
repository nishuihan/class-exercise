#include <stdio.h>
#include <string.h>
int cam_int(void * a, void * b)
{
    int max;
    if (* (int *)a >= * (int *)b) 
    {
        max = *(int *)a;
        * (int *)a = * (int *)b;
        * (int *)b = max;
    }
    return 0; 
}
int cam_char(void * a, void * b)
{
    char max,* aa, * bb;
    aa = (char *)a;
    bb = (char *)b;
    if (* aa >= * bb) //notice: you must campare two values,not two addresses which is " if (aa >> bb) "
    {
        max = *aa;
        *aa = *bb;
        *bb = max;
    }
    return 0;
}
void  sort_small(void * a,int length,int size, int (* fun)(void *,void *))
{
    int i = 0, j = 0;
    for (i = 0; i < length - 1; i++) 
    {
        for (j = 0; j < length - i - 1; j++) 
        {
           fun(a + j * size,a + (j + 1) * size); 
        }
    }
}
int main(int argc, const char *argv[])
{
    int i;
    int a[10]; 
    char a1[10];
    for (i = 0; i < 10; i++) 
    {
        scanf("%d ",a + i);
    }
    printf("you sucess input\n");
    for (i = 0; i < 10; i++) 
    {
        scanf("%c ",&a1[i]);
    }
    sort_small(a,10, 4, cam_int);
    for (i = 0; i < 10; i++) 
    {
        printf("%d", a[i]);
    }
    printf("\n");
    sort_small(a1, 10, 1, cam_char);
    for (i = 0; i < 10; i++) 
    {
        printf("%d\n",a1[i]);
    }
    return 0;
}
