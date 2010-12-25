#include <stdio.h>
struct comand{
    char com[200][100];
    char in[10];
    char out[10];
    int num;
};
int mycmd(char *a, struct comand *b)
{
    int i, j, m, n = 0;
    for (i = 0; a[i] != ' '; i++)
    { 
            (b)->com[0][i] = a[i];
    }
    (b)->com[0][i] = '\0';
    for (; a[i] != '\0'; i++)
    {
        m = 0;
        if (a[i] == '-')
        {
            n++;
            for (;a[i] != ' '; i++)
            {
                (b)->com[n][m] = a[i + 1];
                m++;
            }
            (b)->com[n][m] = '\0'; 
        }
        if (a[i] == '<')
        {
            for (m = 0; a[i] != '\0'; i++)
            {
                (b)->in[m] = a[i + 2];
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
        }
        (b)->num = n;
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    int i;
    char a[100];
    struct comand aa  = {0}; 
    fgets(a, 100, stdin);
    mycmd(a, &aa);
    printf("show the comand : %s\n", aa.com[0]);
    for (i = 0; i < aa.num; i++) 
    {
        printf("the argument %d:  %s\n", i + 1, aa.com[i + 1]);
    }
    printf("outfile is :  %s           ", aa.out);
    printf("infile is  :  %s\n", aa.in);
    return 0;
}
