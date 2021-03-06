#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu{
    int id;
    char *name;
    int chinese;
    int math;
    struct stu *next;
}stu_t;
void creat_file(int n, char *str)
{
    stu_t stu[n];
    int i;
    char buff[100];
    FILE *fp;
    if ((fp = fopen(str, "w+")) == NULL)
        printf("you connot open the file\n");
    for (i = 0; i < n; i++) 
    {
        fgets(buff, 100, stdin);
        fputs(buff, fp);
    }
    rewind(fp);
    //fclose(fp);
}

stu_t * creat_link(stu_t *pro, char *str, int n)
{
    FILE *fp;
    stu_t *p; 
    int i = 0;
    char buff[100];
    if ((fp = fopen(str, "w+")) == NULL)
        printf("please open the correct file\n");
    while(fgets(buff, 100, fp) && i < n)
    {
        p = (stu_t *)malloc(sizeof(stu_t));
        p->id = atoi(strtok(buff, " "));
        p->name = strtok(NULL, " ");
        p->chinese = atoi(strtok(NULL, " " ));
        p->math = atoi(strtok(NULL, " "));
        pro = p->next = pro;
        i++;
    }
    fclose(fp);
    return p;
}
stu_t *sort(stu_t *p)
{
    stu_t *max,*b, *head, *a, *tmp1, *head_new;
    int i, n = 0;
    head = p;
    for (i = 0; i < 3; i++)
    {
        max= p;
        while(p->next != NULL)
        {
            if (p->next->id >= max->id)
            {
                tmp1 = p;
                max = p->next;
            }
            p = p->next;
        }
        if (max == head)
            head = p = max->next;
        else
        {
            if (max->next != NULL && i < 2)
                tmp1->next = tmp1->next->next;
            else
           {
                tmp1->next = NULL;
            }
            p = head;
        }
        if (n == 0)
        {
            a = max;
            head_new = a;
            n = 1;
            continue; 
        }
        a = a->next = max;
    }
    a->next = p;
    return head_new;
}
int main(int argc, const char *argv[])
{
    stu_t *p, *head_new;
    int i = 0;
    //char str[10] = "111";
    //creat_file(2, str);
    //p = creat_link(NULL, str, 2);
    //char str[10] = "111";
    creat_file(2, argv[1]);
    p = creat_link(NULL, argv[1], 2);
    head_new = sort(p);
    for (i = 0; i < 2; i++)
    {
        printf("%d\n", head_new->id);
        head_new = head_new->next;
    }
    return 0;
}
