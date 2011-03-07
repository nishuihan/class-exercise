#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>k

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

void mycp(void)
{
    int source_fd, targt_fd;
    struct stat buffer;
    char buff[1024] = {0};

    if((source_fd = open("aka", O_RDWR)) == -1)
    {
        perror("open");
        exit(1);
    }
    if((targt_fd = open("targt", O_RDWR | O_CREAT, 0777)) == -1)
    {
        perror("open");
        exit(1);
    }
    fstat(source_fd, &buffer);
    read(source_fd, buff, buffer.st_size);
    write(targt_fd, buff, buffer.st_size);
    printf("%d\n", buffer.st_size);
    close(source_fd);
    close(targt_fd);
}

int main(int argc, char *argv[])
{
    mycp();
    
    return 0;
}
