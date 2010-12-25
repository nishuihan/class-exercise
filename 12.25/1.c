#include <stdio.h>
struct comand{
    char com[20][10];
    char in[10];
    char out[10];
};
void mycmd(char *a, struct comand *b)
{
    int i, j, m, n = 1;
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
        for (j = i; a[i + 1] == '-' && a[j] != ' '; j++)
        {
                 (b)->com[n][m] = a[j];
                 m++;
                 
        }
        n++;
        if (a[j + 1] == '<')
        {
            for (m = 0; a[j] != '\0'; j++)
            {
                (b)->in[m] = a[j];
                m++;
            }
        }
        if (a[j + 1] == '>')
        {
            for (m = 0; a[j] != '\0'; j++)
            {
                (b)->out[m] = a[j + 3];
                m++;
            }
            printf("%s\n", (b)->out);
            i = j - 1;
        }
    }
            printf("%s\n", (b)->out);
    //return 0;
}
            


int main(int argc, const char *argv[])
{
    char a[]= "cat > main.c";
    struct comand aa; 
    mycmd(a, &aa);
    printf("sysh is : %s\n", a);
    printf("show the comand : %s\n", aa.com[0]);
    printf("outfile is :%s\n", aa.out);
    return 0;
}
