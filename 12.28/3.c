#include <stdio.h>
#include <stdlib.h>
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
int main(int argc, const char *argv[])
{
    stu_t *p, *max,*b, *head, *a, *tmp1, *head_new;
    int i, n = 0;
    p = creat(NULL, 25);
    p = creat(p, 17);
    p = creat(p, 12);
    p = creat(p, 19);
    head = p;
    for (i = 0; i < 3; i++)
    {
        max= p;
        while(p->next != NULL)
        {
            if (p->next->item >= max->item)
            {
                tmp1 = p;
                max = p->next;
            }
            p = p->next;
        }
        if (max == head)
            head = p = max->next;
        else
        {
            if (max->next != NULL && i < 2)
                tmp1->next = tmp1->next->next;
            else
            {
                tmp1->next = NULL;
            }
            p = head;
        }
        if (n == 0)
        {
            a = max;
            head_new = a;
            n = 1;
            printf("%d\n", a->item);
            continue; 
        }
        a = a->next = max;
        printf("%d\n", max->item);
        //printf("%d\n", tmp1->item);
    }
    a->next = p;
    printf("%d\n", p->item);
    for (i = 0; i < 4; i++)
    {
        printf("%d\n", head_new->item);
        head_new = head_new->next;
    }
    return 0;
}
