#include <stdio.h>
#include <string.h>
typedef struct cmd{
    char *cmd[8];
    char *in_file;
    char *out_file;
}cmd_t;
cmd_t g_cmd;
int parse(char *p)
{
    char *a;
    int n = 0;
    a = p;
    g_cmd.in_file = g_cmd.out_file = NULL;
    while(*p != '\0')
    {
        if (*p == ' ')
        {
            *p = '\0';
            p++;
            continue;
        }
        if(*p == '<')
        {
            p++;
            while(*p++ == ' ');
            g_cmd.in_file = --p;
        }
        if (*p == '>')
        {
            p++;
            while(*p++ == ' ');
            g_cmd.out_file = --p;
        }
        if ((*(p - 1) == '\0') || (p == a))
        {
            g_cmd.cmd[n++] = p;
            p++;
            continue;
        }
        p++;
    }
    g_cmd.cmd[n] = NULL;
    return 0;
} 
void show()
{
    int i;
    for (i = 0; i < 8; i++) 
    {
        if(g_cmd.cmd[i] == NULL)
            break;
        if (i == 0)
            printf("the comand is : %s\n", g_cmd.cmd[0]);
        else 
            printf("the argument %d is : %s\n", i, g_cmd.cmd[i]);
    }
    printf("the infile is : %s\n", g_cmd.in_file);
    printf("the outfile is : %s\n", g_cmd.out_file);
}
int main(int argc, const char *argv[])
{
    char str[10];
    while(1)
    {
        fgets(str, 256, stdin);
        str[strlen(str)- 1] = '\0';
        parse(str);
        show();
    }
    return 0;
}
