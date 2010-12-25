#include <stdio.h>
#include <string.h>
typedef struct stu
{
    char name[20];
    int remark;
    void (* fun_t)(void);
}stu_t;
stu_t stu1[5];
void print_1(void)
{
    printf("*\n");
}
int main(int argc, const char *argv[])
{
    int i = 0; 
    //char ss[10];
    for (i = 0; i < 5; i++) 
    {
        //scanf("%s %d", ss, &code);
        //stu1[i].remark = code;
        //scanf("%s %d", ss, &stu1[i].remark);//noitce
        scanf("%s %d", stu1[i].name, &stu1[i].remark);//noitce
        //strcpy(stu1[i].name, ss);
    }
    for (i = 0; i < 5; i++) 
    {
        stu1[i].fun_t = print_1;
        printf("%s %d ",stu1[i].name, stu1[i].remark);
        stu1[i].fun_t();
    }
    return 0;
}
