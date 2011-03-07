#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <string.h>
#include <sys/mman.h>

void mycp(void)
{
    int s_fd, t_fd;
    int *s_p, *t_p;
    struct stat s_file;

    if((s_fd = open("111", O_RDWR)) == -1)
    {
        perror("open 111");
        exit(1);
    }
    fstat(s_fd, &s_file);
    s_p = mmap(0, s_file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, s_fd, 0);

    if((t_fd = open("222", O_RDWR |O_CREAT, 0777)) == -1)
    {
        perror("open 222");
        exit(1);
    }
    lseek(t_fd, s_file.st_size - 1, SEEK_SET);
    write(t_fd, "1", 1);
    t_p = mmap(0, s_file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, t_fd, 0);

    memcpy(t_p, s_p, s_file.st_size);
}

int main(void)
{
   mycp();

   return 0;
}
     


            

