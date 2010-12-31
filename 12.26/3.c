#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu{
    int id;
    int chinese;
    char name[100];
    struct stu *next;
}stu_t;
stu_t *creat(stu_t *pro, int id, int chi, char *name)
{
    stu_t *p = (stu_t *)malloc(sizeof(stu_t));
    p->id = id;
    p->chinese = chi;
    strcpy(p->name, name);
    p->next = NULL;

    pro->next = p;
    return p;
}
void bianli(stu_t *p)
{
    while(p != NULL)
    {
        printf("%d %d %s\n", p->id, p->chinese, p->name);
        p = p->next;
    }
}
stu_t * delate(stu_t *p, int id)
{
    stu_t *a = NULL;
    stu_t *head;
    head = p;
    if (p->id == id)
    {
        p = p->next;
        free(head);
        head = NULL;
        return p;
    }
    while(p->next != NULL)
    {
        if (p->next->id == id)
        {
            a = p->next;
            p->next = (p->next)->next;
            //continue;
        }
        else
        {
            p = p->next;
        }
        free(a);
        a = NULL;
    }
    return head;
}
void insert_next(stu_t *next,int id, int chi, char *name)
{
        stu_t *source;
        source = (stu_t *)malloc(sizeof(stu_t));
        source->id = id;
        source->chinese = chi;
        strcpy(source->name,name);
        source->next = next->next;
        next->next = source;
}
int main(int argc, const char *argv[])
{
    stu_t *a[10];
    int i;
    char temp[100];
    a[0] = (stu_t *)malloc(sizeof(stu_t));
    a[0]->id = 1001;
    a[0]->chinese = 40;
    strcpy(a[0]->name, "dongjie");
    for (i = 0; i < 10; i++) 
    {
        if(i == 9) break;
        a[i + 1] = creat(a[i], 1001 + i, 90 + i, "dongjie");
        printf("%p, %d, %d, %s\n", a[i]->next, a[i]->id, a[i]->chinese, a[i]->name);
        printf("%p, %d, %d, %s\n", a[i+ 1], a[i +1]->id, a[i + 1]->chinese, a[i + 1]->name);
    }
    bianli(a[0]);
    a[0] = delate(a[0], 1009);
    bianli(a[0]); 
    insert_next(a[3],1200, 999, "lisi");
    bianli(a[0]);
    return 0;
}
