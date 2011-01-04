#include <stdio.h>
typedef struct stu{
    int item;
    int id;
}stu_t;
int main(int argc, const char *argv[])
{
    stu_t stu1 = {100, 20};
    FILE *fp1, *fp2;
    fp1 = fopen("11", "w+");
    fprintf(fp1, "%s,%s\n", "item", "id"); 
    fprintf(fp1, "%d,%5d", stu1.id, stu1.item); 
    fscanf(fp1, "%d%d", &stu1.id, &stu1.item);
    printf("%d, %d\n", stu1.id, stu1.item);
    return 0;
}
