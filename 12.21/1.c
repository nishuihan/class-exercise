#include <stdio.h>
#include <string.h>
int cam_int(void * a, void * b)
{
    return * (int *)a - * (int *)b;
}
int cam_char(void * a, void * b)
{
    return * (char *)a - * (char *)b;
}
void  sort_small(void * a,int length,int size, int (* fun)(void *,void *))
{
    int max;
    int i = 0, j = 0;
    for (i = 0; i < length - 1; i++) 
    {
        for (j = 0; j < length - i - 1; j++) 
        {
            if (cam_int( (a + j * size),  (a + (j + 1) * size)) >= 0) 
            {
                 max = *(int *)(a + j * size);
                 * (int *)(a + j * size) =  * (int *)(a + (j +1) * size);
                 * (int *)(a + (j + 1) * size) = max;
            }
        }
    }
}
//void  sort_small(int * a,int length,int size, int (* fun)(void *,void *))
//{
    //int  max;
    //int i = 0, j = 0;
    //for (i = 0; i < length - 1; i++) 
    //{
        //for (j = 0; j < length - i - 1; j++) 
        //{
            //if (cam_int( (a + j),  (a + j + 1)) >= 0) 
            //{
                 //max = * (a + j);
                 //* (a + j) =  * (a + j +1);
                 //* (a + (j + 1)) = max;
            //}
        //}
    //}
//}
int main(int argc, const char *argv[])
{
    int i;
    int a[10] = {3,4,29,22,11,2,8,9,21,20};
    sort_small(a,10, 4, cam_int);
    for (i = 0; i < 10; i++) 
    {
        printf("%d ", a[i]);
    }
    return 0;
}
