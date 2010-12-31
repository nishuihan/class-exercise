#include <stdio.h>
typedef struct stu{
    char name[10];
    int num;
}stu_t;
stu_t stu[10];
void save(void)
{
    FILE *fp;
    int i;
    if ((fp = fopen("11", "w+")) == NULL)
    {
        printf("cannot open the file\n");
        return;
    }
    for (i = 0; i < 4; i++) 
        fwrite(&stu[i], sizeof(stu_t), 1, fp);
    fclose(fp);
}
int main(int argc, const char *argv[])
{
    
    int i;
    for (i = 0; i < 4; i++) 
        scanf("%s%d", stu[i].name, &stu[i].num);
    save();
    return 0;
}
