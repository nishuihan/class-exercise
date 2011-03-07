#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>k

#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    fd = open("aka",O_RDWR | O_CREAT, 00777);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    write(fd, "hello", 5);
    close(fd);

    return 0;
}
