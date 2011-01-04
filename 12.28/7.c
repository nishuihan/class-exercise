#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu{
    int id;
    char name[100];
    int chinese;
    int math;
    float average;
    struct stu *next;
}stu_t;
int n = 1;

void creat_file_from_stu(stu_t *p)
{
    int i;
    char buff[100];
    FILE *fp;
    if ((fp = fopen("file.txt", "w")) == NULL)
        printf("you connot open the file\n");
    for (i = 0; i < n; i++) 
    {
        fprintf(fp, "%d %s %d %d\n",p->id, p->name, p->chinese, p->math);
        p = p->next;
    }
    fclose(fp);
}


stu_t * creat_link(stu_t *pro)
{
    FILE *fp;
    stu_t *p, *tmp, *head; 
    int i = 0;
    n = 1;
    char buff[100];
    if ((fp = fopen("file.txt", "r")) == NULL)
        printf("please read the correct file\n");
    while(1)
    {
        p = (stu_t *)malloc(sizeof(stu_t));
        if (fscanf(fp, "%d%s%d%d",&p->id, p->name, &p->chinese, &p->math) == EOF)
        break;
        p->average = (p->chinese + p->math) / 2;
        if (i == 0)
        {
            p->next = pro;
            head = tmp = p;
            i++;
            continue;
        }
        tmp->next = p;
        tmp = p;
        n++;
    }
    fclose(fp);
    return head;
}

stu_t *sort(stu_t *p)
{
    stu_t *max,*b, *head, *a, *tmp1, *head_new;
    int i, flag = 0;
    head = p;
    for (i = 0; i < n - 1; i++)
    {
        max= p;
        while(p->next != NULL)
        {
            if (p->next->average >= max->average)
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
            if (max->next != NULL && i < n - 2)
                tmp1->next = tmp1->next->next;
            else
           {
                tmp1->next = NULL;
            }
            p = head;
        }
        if (flag == 0)
        {
            a = max;
            head_new = a;
            flag = 1;
            continue; 
        }
        a = a->next = max;
    }
    a->next = p;
    return head_new;
}

void display_info(stu_t *p)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%3d   %7s   %3d   %3d   %3.2f\n", p->id, p->name, p->math, p->chinese, p->average);
        p = p->next;
    }
}

stu_t * insert(stu_t *p)
{
    stu_t *new = malloc(sizeof(stu_t));
    stu_t *head;
    FILE *fp;
    char name[100];
    n++;
    printf("Input id: ");
    scanf("%d", &new->id);
    printf("Input name: ");
    scanf("%s", new->name);
    printf("Input chinese: ");
    scanf("%d", &new->chinese);
    printf("Input math: ");
    scanf("%d", &new->math);
    new->average = (new->chinese + new->math) / 2;
    head = p;
    while(p->next!= NULL)
        p = p->next;
    p->next = new;
    if ((fp = fopen("file.txt", "a+")) == NULL)
        printf("Please open the correct file\n");
    fprintf(fp, "%d %s %d %d\n",new->id, new->name, new->chinese, new->math);
    fflush(fp);
    return head;
}

stu_t * delate_id(stu_t *p)
{
    int id; 
    stu_t *head, *pro;
    printf("Please input the id:");
    scanf("%d", &id);
    head = p;
    while(p != NULL)
    {
        if (p->id == id)
        break;
        pro = p;
        p = p->next;
    }
    n--;
    if (p == head)
    {
        head = p->next;
        free(p);
        p = NULL;
        return head;
    }
    else
        pro->next = pro->next->next;
    free(p);
    p = NULL;
    return head;
}

stu_t * delate_name(stu_t *p)
{
    stu_t *head, *pro;
    char name[100];
    n--;
    printf("Please input the name:");
    scanf("%s", name);
    head = p;
    while(p != NULL)
    {
        if (!strcmp(p->name, name))
        break;
        pro = p;
        p = p->next;
    }
    if (p == head)
    {
        head = p->next;
        free(p);
        p = NULL;
        return head;
    }
    else
        pro->next = pro->next->next;
    free(p);
    p = NULL;
    return head;
}

void display(void)
{
    printf("Plase select the option:\n");
    printf("1.Dsiplay all student's info\n");
    printf("2.Sort by average\n");
    printf("3.Insert a new info\n");
    printf("4.Delate a record\n");
    printf("5.Quit\n");
    printf("Please input your choice: ");
}

void display_delate(void)
{
    printf("Please choose the way:\n");
    printf("1.Delate by id:\n");
    printf("2.Delate by name:\n");
    printf("3.Exit\n");
    printf("Your choose:");
}

int main(int argc, const char *argv[])
{
    stu_t *p, *head_new;
    int i = 0, num, num_delate;
    p = creat_link(NULL);
    while(1)
    {
        display();
        scanf("%d", &num);
        switch(num)
        {
            case 1:	
                display_info(p);
                getchar();
                break;
            case 2:
                display_info(sort(p));
                p = creat_link(NULL);
                getchar();
                break;
            case 3:
                display_info(insert(p));
                getchar();
                break;
            case 4:
                while(1)
                {
                    display_delate();
                    scanf("%d", &num_delate);
                    getchar();
                    if (num_delate == 1)
                        creat_file_from_stu(delate_id(p));
                    else if (num_delate == 2)
                        creat_file_from_stu(delate_name(p)); 
                        else if (num_delate == 3)
                            break;
                    getchar();
                }
                break;
            case 5:
                return 0;
        }
        getchar();
        p = creat_link(NULL);
        }
    return 0;
}
