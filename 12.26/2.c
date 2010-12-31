#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu{
    int id;
    int chinese;
    char name[256];
    struct stu *next;
};
struct stu * creat(struct stu *pro, int id, int chi, char *name)
{
    
   struct stu * p = (struct stu *)malloc(sizeof(struct stu));
    p->id = id;
    p->chinese = chi;
    strcpy(p->name,name);
    p->next = NULL;

    pro->next = p;
    return p;
}
int main(int argc, const char *argv[])
{
    struct stu *stu1, *a[10]; 
    stu1 = (struct stu *)malloc(sizeof(struct stu));
    stu1->id = 1001; 
    stu1->chinese = 99; 
    strcpy(stu1->name, "dongjie");
    a[0] = creat(stu1, 1002, 98, "dongjie2");
    printf("%p\n", stu1->next);
    printf("%p\n", a[0]);
    a[1] = creat(a[0], 1003, 98, "dongjie2");
    printf("%p\n", a[0]->next);
    printf("%p\n", a[1]);
    a[2] = creat(a[1], 1004, 98, "dongjie2");
    printf("%p\n", a[1]->next);
    printf("%p\n", a[0]);
    a[3] = creat(a[2], 1005, 98, "dongjie2");
    printf("%p\n", a[2]->next);
    printf("%p\n", a[3]);
    a[4] = creat(a[3], 1006, 98, "dongjie2");
    printf("%p\n", a[3]->next);
    printf("%p\n", a[4]);
    return 0;
}
