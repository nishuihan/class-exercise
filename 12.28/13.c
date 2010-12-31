#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp1, *fp2;
    fp1 = fopen("11", "r");
    fp2 = fopen("22", "w");
    char aa[100];
    fread(aa, 5,4, fp1);
    aa[21] = '\n';
    printf("%s\n", aa);
    fwrite(aa, 3, 7, fp2);
    return 0;
}
