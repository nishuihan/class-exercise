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
int (* bianli)(stu_t *p)
{
    while(p != NULL)
    {
        printf("%d %d %s\n", p->id, p->chinese, p->name);
        p = p->next;
    }
    return 0;
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

        //printf("%p\n", a[i + 1]);
    }
    bianli(a[0]);
    return 0;
}
