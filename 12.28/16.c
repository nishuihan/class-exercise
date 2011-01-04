#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char *name;
    int math;
    int chinese;
}stu_t;
int main(int argc, const char *argv[])
{
    FILE *fp;
    char buff[100] = {'1'};
    int n;
    stu_t stu[3];
    fp = fopen("11", "w+");
    if (!fp)
    {
        perror("open file");
        exit(1);
    }
    printf("please input id, name, math, chinese\n");
    for (n = 0; n < 3; n++)
    {
        fgets(buff, 100, stdin);
        fputs(buff, fp);
    }
    rewind(fp);
    n = 0;
    while(fgets(buff, 100, fp))
    //while(fread(buff, sizeof(stu_t), 1, fp))
    {
        stu[n].id = atoi(strtok(buff, " "));
        stu[n].name = strtok(NULL, " ");
        stu[n].chinese = atoi(strtok(NULL, " " ));
        stu[n].math = atoi(strtok(NULL, " "));

        n++;
    }
    rewind(fp);
    for (n = 0; n < 3; n++)
    {
        printf("%d, %s, %d, %d\n", stu[n].id, stu[n].name, stu[n].chinese, stu[n].math);
    }
    return 0;
}
