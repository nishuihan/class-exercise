#include <stdio.h>
#include <string.h>
struct stu_t
{
    char name[20];
    int remark;
};
struct stu_t stu1[5];
int main(int argc, const char *argv[])
{
    int i=0; 
    strcpy(stu1[0].name,"zhangshan");
    strcpy(stu1[1].name,"dongjie");
    strcpy(stu1[2].name,"zhangli");
    strcpy(stu1[3].name,"zhangdong");
    strcpy(stu1[4].name,"zhnagjie");
    for (i = 0; i < 5; i++) 
    {
        printf("%s\n",stu1[i].name);
    }
    return 0;
}
