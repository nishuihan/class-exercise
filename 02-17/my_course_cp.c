#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <string.h>
#include <sys/mman.h>

void mycp(int fd, int fp, int *start, int lenght)
{

} 
void course_cp(int n)
{
    int s_fd, t_fd;
    char *s_addr, *t_addr;
    int i = 0;
    int tmp[10] = {0};
    struct stat file;

    if((s_fd = open("111", O_RDWR)) == -1)
    {
        perror("open 111");
        exit(-1);
    }
    fstat(s_fd, &file);
    s_addr = mmap(0, file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, s_fd, 0);
    
    if((t_fd = open("222", O_RDWR | O_CREAT, 0777)) == -1)
    {
        perror("open 222");
        exit(-1);
    }
    lseek(t_fd, file.st_size - 1, SEEK_SET);
    write(t_fd, "1", 1);
    t_addr = mmap(0, file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, t_fd, 0);
    
    tmp[0] = fork();
    if(tmp[0] < 0)
    {
        perror("fork 0");
        exit(-1);
    }
    if(tmp[0] == 0)
    {
        memcpy(t_addr, s_addr, file.st_size / n);
                    printf("1");
                    printf("s1%d\n", getpid());
    }
    //else
    if(tmp[0] > 0)
    {
        for(i=1; i<n; i++)
        {
            if(tmp[i - 1] > 0)
            {
                tmp[i] = fork();
                if(tmp[i] < 0)
                {
                    perror("fork");
                    exit(-1);
                }
                if(tmp[i] == 0)
                {
                    memcpy(t_addr + file.st_size* i / n , s_addr + file.st_size* i / n , file.st_size / n);
                    perror("son2 memcpy");
                    printf("3");
                    printf("s3%d\n", getpid());
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
   printf("%d", atoi(argv[1]));
                    printf("praent%d\n", getpid());
   course_cp(atoi(argv[1]));

   return 0;
}


