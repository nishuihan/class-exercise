#include <stdio.h>
struct comand{
    char com[20][10];
    char in[10];
    char out[10];
    int num;
};
void mycmd(char *a, struct comand *b)
{
    int i, j, m, n = 0;
    for (i = 0; a[i] != ' '; i++)
    { 
            (b)->com[0][i] = a[i];
    }
    (b)->com[0][i] = '\0';
    printf("%s\n", (b)->com[0]);
    for (; a[i] != '\0'; i++)
    {
        //j = i;
        m = 0;
        if (a[i] == '-')
        {
                   n++;
            for (;a[i] != ' '; i++)
            {
                     (b)->com[n][m] = a[i];
                     m++;
                     
            }
             (b)->com[n][m] = '\0'; 

        }
        if (a[i] == '<')
        {
            for (m = 0; a[i] != '\0'; i++)
            {
                (b)->in[m] = a[i];
                m++;
            }
        }
        if (a[i] == '>')
        {
            for (m = 0; a[i] != '\0'; i++)
            {
                (b)->out[m] = a[i + 2];
                m++;
            }
            printf("%s\n", (b)->out);
            //i = j - 1;
        }
        (b)->num = n;
    }
            printf("%s\n", (b)->out);
            printf("%d\n", (b)->num);
    //return 0;
}
            


int main(int argc, const char *argv[])
{
    int i;
    char a[]= "cat -g -h > main.c";
    struct comand aa; 
    mycmd(a, &aa);
    printf("sysh is : %s\n", a);
    printf("show the comand : %s\n", aa.com[0]);
    for (i = 0; i < aa.num; i++) 
    {
        printf("the argument %d : %s     ", i, aa.com[i + 1]);
    }
    printf("\n");
    printf("outfile is :%s\n", aa.out);
    return 0;
}
