#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu{
    int id;
    char name[256];
};
void swap(struct stu *a,struct stu *b)
{
    struct stu  aa;
        aa = *a;
      *a = *b;
       *b= aa;
}    
int main(int argc, const char *argv[])
{
    int i, j;
    struct stu *stu1;
    struct stu *stu2;
    stu1 = (struct stu *)malloc( sizeof(struct stu ) * 10);
    stu2 = (struct stu *)malloc( sizeof(struct stu ) * 10);
    printf("%p\n", stu1);
    printf("%p\n", stu2);
    for (i = 0; i < 10; i++) 
    {
        (stu1 + i)->id = i + 1;
        (stu2 + i)->id = 2 * (i + 1);
    }
    for (i = 0; i < 10; i++) 
    {
        printf("%d\n", (stu1 + i)->id);
        printf("%d\n", stu2[i].id);
    }
    swap(stu1,stu2);
    for (i = 0; i < 10; i++) 
    {
        printf("%d\n", stu1[i].id);
        printf("%d\n", stu2[i].id);
    }

    return 0;
}
