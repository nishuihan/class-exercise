#include <stdio.h>
#include <stdlib.h>
typedef struct stu{
    int item;
    struct stu *next;
}stu_t;
stu_t * creat(stu_t *pro, int item)
{
    stu_t *p1;
    p1 = (stu_t *)malloc(sizeof(stu_t));
    p1->item = item;
    p1->next = pro;
    
    return p1;
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
            if (p->next->item >= max->item)
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
    stu_t stu[10];
    int i;
    FILE *fp1, *fp2;
    int str;
    fp1 = fopen("11", "w");
    fprintf(fp1,"%d %d %d %d", 13, 24, 35, 10);
    fclose(fp1);
    fp2 = fopen("11", "wb+");
    fread(&str, 4, 1, fp2);
    printf("%d\n", str);
   /* 
    p = creat(NULL, str);
    fread(str, 1, 1, fp1);
    p = creat(p, str);
    fread(str, 1, 1, fp1);
    p = creat(p, str);
    fread(str, 1, 1, fp1);
    p = creat(p, str);*/
    //p = creat(p, str);
    //p = creat(p, fread(str, 1, 2, fp1));
    //p = creat(p, fread(str, 1, 2, fp1));
    head_new = sort(p);
    for (i = 0; i < 4; i++)
    {
        printf("%d\n", head_new->item);
        head_new = head_new->next;
    }
    return 0;
}
