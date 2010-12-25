#include <stdio.h>
#include <string.h>
struct cmd{
    char *cmd[10];
    char *in;
    char *out;
};
int n = 0;
int mycmd(char *a, struct cmd *str)
{
    while(*a != '\0')
    {
        if (*a == ' ')
        {
            *a = '\0';
            a++;
            continue;
        }
        if (*(a - 1) == '\0')
        {
            (str)->cmd[n] = a;
            n++;
            a++;
            continue;
        }
        if ((*a == '<') || (*a == '>'))
        {
            if (*a == '<')
            {
                a++;
                while(*a++ == ' ');
                (str)->in = --a;
            }
            if (*a == '>')
            {
                a++;
                while(*a++ == ' ');
                (str)->out = --a;
            }
            continue;
        }
        a++;
    }
    (str)->cmd[n] = NULL;
   return 0; 
} 
int main(int argc, const char *argv[])
{
    char aa[100] = "ls -g < ma";
    struct cmd cmd1 = {0};
    int i;
    //fgets(aa, 100, stdin);
    mycmd(aa, &cmd1);
    printf("%d\n", n);
   for (i = 0; i < n; i++) 
   {
       printf("%s\n", cmd1.cmd[i]);
   }
   
    return 0;
}
