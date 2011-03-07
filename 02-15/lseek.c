#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    int tmp = 0;
    
    if((fd = open("111", O_RDWR | O_CREAT, 0777)) == -1)
    {
        perror("open");
        exit(1);
    }
    tmp = lseek(fd, 2, SEEK_END); //pay attention to the offset and whence
    write(fd, "hello", 5);
    printf("%d\n", tmp);
    close(fd);

    return 0;
}
