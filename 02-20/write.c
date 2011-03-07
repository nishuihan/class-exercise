#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int n = 11111;
    int i = 11111;
    int fd;

    fd = open("111", O_RDWR | O_CREAT, 00777);
    if(fd == -1)
        perror("open");
   

    for(; i>0; i--)
    {
        for(; n>0; n--)
        {
            //printf("%d\n", n);
            write(fd, "I am zhangzhenshan, I am success !", 40);
        }
    }
    close(fd);

    return 0;
}
