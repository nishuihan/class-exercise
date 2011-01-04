#include <stdio.h>
typedef struct{
    int id;
    char name[100];
}stu_t;
int main(int argc, const char *argv[])
{
    stu_t stu[2];
    FILE *fp = fopen("11", "w+");
    char buff[100];
    int i, id;
    char name[10];
    for (i = 0; i < 2; i++) 
    {
       fscanf(stdin, "%d %s", &id, name);
       fprintf(fp, "%d%s\n", id, name);
       
    }
    rewind(fp);
    fp = fopen("11", "r");
    for (i = 0; i < 2; i++) 
    {
        fscanf(fp,"%d%s", &stu[i].id,stu[i].name); 
        printf("%d %s\n", stu[i].id, stu[i].name);

    }
    return 0;
}
