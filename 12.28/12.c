#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    char tmp[1000], tmp1[20];
    //fgets(tmp, 1000, fp1);
    //fputs(tmp, fp2);
    printf("%s\n", tmp);
    //tmp = fgetc(fp1);
    //while(tmp != EOF)
    while(!feof(fp1))
    {
        //printf("%c\n", fgetc(fp1));
        //fputc(tmp, fp2);
        //tmp = fgetc(fp1);
    fgets(tmp, 1000, fp1);
    fputs(tmp, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
