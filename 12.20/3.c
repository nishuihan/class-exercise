#include <stdio.h>
#include <string.h>
struct stu_t
{
    char name[20];
    int remark;
    void (* fun_t)(void);
}stu2;
struct stu_t stu1[5];
void print_1(void)
{
    printf("*\n");
}
int main(int argc, const char *argv[])
{
    int i = 0,code = 0; 
    char ss[10];
    printf("%d\n", sizeof(stu2));
    for (i = 0; i < 5; i++) 
    {
        scanf("%s %d", ss, &code);
        stu1[i].remark = code;
        strcpy(stu1[i].name, ss);
    }
    for (i = 0; i < 5; i++) 
    {
        stu1[i].fun_t = print_1;
        printf("%s %d ",stu1[i].name, stu1[i].remark);
        stu1[i].fun_t();
    }
    return 0;
}
