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
    stu_t *end, *head1, *head2, *new_head;
    int i,j ;
    head1 = p;
    for (i = 0; i < 3; i++)
    {
        p = p->next;
    }
    //printf("%d\n", p->id);
    new_head = end = p;
    for (i = 0; i < 3; i++)
    {
        head2 = head1; 
        for (j = 0; j < 2 - i; j++)
            head2 = head2->next;
        end->next = head2;
        end = end->next;
        //printf("%d\n", end->id);
    }
    return new_head;
}



       
int main(int argc, const char *argv[])
{
    stu_t *p, *link_end, *head;
    int i;
    head = p = creat_link(2);
    for (i = 0; i < 4; i++)
    {
        printf("id = %d\n", p->id);
        p = p->next;
    }
    link_end = end(head);
    for (i = 0; i < 4; i++)
    {
        printf("id = %d\n", link_end->id);
        link_end = link_end->next;
    }
        return 0;
}
