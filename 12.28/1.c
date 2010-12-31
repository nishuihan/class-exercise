#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct stu{
    int item;
    struct stu *next;
}stu_t;
stu_t * creat(stu_t *pro, int item)
{
    stu_t *p1;
    p1 = (stu_t *)malloc(sizeof(stu_t));
    p1->item = item;
    p1->next = pro;
    
    return p1;
}
stu_t * josephus(int n, stu_t *head)
{
    int i = 0;
    while( head != head->next)
    {
        if (i + 1 == n)
        {
            printf("%d\n", head->next->item);
            head = head->next = head->next->next;
            i = 0;
        }
        i++;
        head = head->next;
    }
    return head;
}
int main(int argc, const char *argv[])
{
    stu_t *stu1,*p;
    int i = 0;
    p = (stu_t *)malloc(sizeof(stu_t));
    p->item = 1;
    p->next = NULL;
    stu1 = p;
    for (i = 0;i < N - 1; i++)
        p = creat(p, i + 2); 
    stu1->next = p;
    for (i = 0; i < N; i++)
    {
        printf("the %d is : item = %d\n", i + 1,p->item );
        p = p->next;
    }
    printf("%d\n", josephus(2, p)->item);
    return 0;
}
