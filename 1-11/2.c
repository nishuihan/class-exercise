#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{
    int id;
    struct stu *next;
}stu_t;
stu_t *creat_link(int i)
{
    stu_t *p, *head, *pro;
    int num;
    for (num = 0; num < 4; num++)
    {
        p = (stu_t *)malloc(sizeof(stu_t));
        p->id = i;
        if (num == 0)
        {
            head = p;
            pro = p;
            i++;
            continue;
        }
        pro->next = p;
        pro = p;
        i++;
    }
    p->next = NULL;
    return head;
}
stu_t * end(stu_t *p)
{
    stu_t *tmp, *head, *end;
    int i = 0,j = 0 ;
    for (i = 0; i < 4; i++)
    {
        tmp = p; 
        for (j = i; j < 3; j++)
            tmp = tmp->next;
        if (j == 0)
        {
             end = head = tmp;
             continue;
        }
        head->next = tmp;
        head = tmp;
        printf("%5d\n", head->id);
    }
    head->next = NULL; 
    return end;
}
void printf_link(stu_t *p)
{
    while(p!= NULL)
    {
        printf("%5d", p->id);
        p = p->next;
    }
    printf("\n");
}
       
int main(int argc, const char *argv[])
{
    stu_t *head;
    head = creat_link(2);
    printf_link(head);
   head = end(head);
   printf_link(head);
    return 0;
}
