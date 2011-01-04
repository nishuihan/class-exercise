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
void creat_file_from_stdin(int n)
{
    int i;
    char buff[100];
    FILE *fp;
    if ((fp = fopen("111", "w")) == NULL)
        printf("you connot open the file\n");
    for (i = 0; i < n; i++) 
    {
        fgets(buff, 100, stdin);
        fputs(buff, fp);
    }
    rewind(fp);
    //fclose(fp);
}
void creat_file_from_stu(stu_t *p, int n)
{
    int i;
    char buff[100];
    FILE *fp;
    if ((fp = fopen("111", "w")) == NULL)
        printf("you connot open the file\n");
    for (i = 0; i < n; i++) 
    {
        fprintf(fp, "%d %s %d %d\n",p->id, p->name, p->chinese, p->math);
        p = p->next;
    }
    rewind(fp);
    fclose(fp);
}


stu_t * creat_link(stu_t *pro, int n)
{
    FILE *fp;
    stu_t *p, *tmp; 
    int i = 0;
    char buff[100], tmp_name[100];
    if ((fp = fopen("111", "r")) == NULL)
        printf("please open the correct file\n");
    while(i < n)
    {
        p = (stu_t *)malloc(sizeof(stu_t));
        fscanf(fp, "%d%s%d%d",&p->id, p->name, &p->chinese, &p->math); 
        p->average = (p->chinese + p->math) / 2;
        if (i == 0)
        {
            p->next = pro;
            tmp = p;
            i++;
            continue;
        }
        p->next = tmp;
        tmp = p;
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
void display_info(stu_t *p, int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%d %s %d %d %f\n", p->id, p->name, p->math, p->chinese, p->average);
        p = p->next;
    }
}
//void insert(stu_t *p, int id, char *name, int chinese, int math)
stu_t * insert(stu_t *p)
{
    int id, chinese, math; 
    stu_t *new = malloc(sizeof(stu_t));
    stu_t *head;
    FILE *fp;
    char name[100];
    printf("id name chinese math\n");
    scanf("%d %s %d %d\n", &new->id, new->name, &new->chinese, &new->math);
    getchar();
    head = p;
    while(p->next != NULL)
        p = p->next;
    p->next = new;
    id = new->id;
    chinese = new->chinese;
    math = new->math;
    strcpy(name, new->name);
    if ((fp = fopen("111", "a")) == NULL)
        printf("fuck\n");
    printf("%d%s%d%d\n",new->id, new->name, new->chinese, new->math);
    //fprintf(fp, "%d%s%d%d\n",new->id, new->name, new->chinese, new->math);
    fprintf(fp, "%d %s %d %d\n",id, name, chinese, math);
    fflush(fp);
    return head;
}
stu_t * delate_id(stu_t *p)
{
    int id, chinese, math; 
    stu_t *head, *pro;
    char name[100];
    printf("Please input the id:");
    scanf("%d", &id);
    head = p;
    while(p->next != NULL)
    {
        if (p->id == id)
        break;
        pro = p;
        p = p->next;
    }
    if (pro == head)
    {
        pro->next = pro->next->next;
        return pro;
    }
    else
        pro->next = pro->next->next;
    return head;
}
stu_t * delate_name(stu_t *p)
{
    int id, chinese, math; 
    stu_t *head, *pro;
    char name[100];
    printf("Please input the name:\n");
    //scanf("%d %s %d %d\n", &id, name, &chinese, &math);
    scanf("%s", name);
    head = p;
    while(p->next != NULL)
    {
        if (p->name == name)
        break;
        pro = p;
        p = p->next;
    }
    if (pro == head)
    {
        pro->next = pro->next->next;
        return pro;
    }
    else
        pro->next = pro->next->next;
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
    //char str[10] = "111";
    //creat_file(2, str);
    //p = creat_link(NULL, str, 2);
    //char str[10] = "111";
    creat_file_from_stdin(4);
    p = creat_link(NULL, 4);
    //head_new = sort(p);
    while(1)
    {
        display();
        scanf("%d", &num);
        switch(num)
        {
            case 1:	
                display_info(p, 4);
                break;
            case 2:
                display_info(sort(p), 4);
                break;
            case 3:
                display_info(insert(p), 5);
                break;
            case 4:
                while(1)
                {
                display_delate();
                scanf("%d", &num_delate);
                getchar();
                if (num_delate == 1)
                    display_info(delate_id(p), 3); 
                else if (num_delate == 2)
                    display_info(delate_name(p), 3); 
                    else if (num_delate == 3)
                        break;
                        }
                        break;
            case 5:
                return 0;
        }
        }
    //for (i = 0; i < 4; i++)
    //
    //{
    //printf("%d %s %d %d %f\n", head_new->id, head_new->name, head_new->math, head_new->chinese, head_new->average);
    //head_new = head_new->next;
        //}
    return 0;
}
