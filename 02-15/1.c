#include <stdio.h>

int mystrstr(const char *str, const char *srcstr)
{
    int num = 0;
    int i = 0, j = 0;

    for(i=0; srcstr[i]!='\0'; i++)
    {
        while(str[j] == srcstr[i] && str[j] != '\0') 
        {
            j++, i++; 
           
            if(str[j] == '\0')
            {
                num++;
                i--;
                j = 0;
                break;
            }
        }
        j = 0;
    }

    return num;
}

int myrep_str_str(char *str,  char *srcstr, const char *replacestr)
{
    int num = 0;
    int i = 0, j = 0, n = 0;

    for(i=0; srcstr[i]!='\0'; i++)
    {
        while(str[j] == srcstr[i] && str[j] != '\0') 
        {
            j++, i++; 
            if(str[j] == '\0')
            {
                num++;
                i--;
                for(n=0; n<j; n++)
                    srcstr[i-j+n+1] = replacestr[n];
                j = 0;
                break;
            }
        }
        j = 0;
    }

    return num;
}

int main(int argc, char *argv[])
{
    //char str[] = "chinainain chain";
    //char str1[] = "in";
    //char str2[] = "12";
    int num = 0;
    int num1 = 0;

    //num = mystrstr(str1, str);
    //num1 = mystrstr(argv[2], argv[1]);
    //num =myrep_str_str(str1, str, str2);
    num = myrep_str_str(argv[2], argv[1], argv[3]);
    printf("%d\n", num);
    //printf("%d\n", num1);
    printf("%s\n", argv[1]);

    return 0;
}




