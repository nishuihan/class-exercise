#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char buf[10];
    int n;

    n = read(STDIN_FILENO, buf, 10);
    if(n < 0)
    {
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);
    printf("\n");

    return 0;
}
