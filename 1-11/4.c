#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
    
    char buf[10];
    int n;
    n = read(STDIN_FILENO, buf, 10);
    if(n < 0)
    {
        perror("read");
        exit(1);
    }
    write(STDIN_FILENO, buf, n);
    return 0;
}
