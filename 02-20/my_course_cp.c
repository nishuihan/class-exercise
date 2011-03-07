#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <string.h>
#include <sys/mman.h>

#include <pthread.h>

struct file
{
    char *s_addr;
    char *t_addr;
    int len;
    int progress;
};
struct file tmp;
pthread_t ntid;

void *mycp(void *p)
{
    struct file *tmp;
    tmp = (struct file *)p; 
    memcpy(tmp->t_addr, tmp->s_addr, tmp->len);  
    tmp->progress++;

    return NULL;
} 

void course_cp(int n)
{
    int s_fd, t_fd;
    int i = 0;
    int err;
    struct stat file;
    float percent = 0;
    tmp.progress = 0;

    if((s_fd = open("111", O_RDWR)) == -1)
    {
        perror("open 111");
        exit(-1);
    }
    fstat(s_fd, &file);
    tmp.s_addr = mmap(0, file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, s_fd, 0);
    
    if((t_fd = open("222", O_RDWR | O_CREAT, 0777)) == -1)
    {
        perror("open 222");
        exit(-1);
    }
    lseek(t_fd, file.st_size - 1, SEEK_SET);
    write(t_fd, "1", 1);
    tmp.t_addr = mmap(0, file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, t_fd, 0);

    for(i=0; i<n; i++)
    {
        tmp.len = file.st_size * (i + 1) / n;
        err = pthread_create(&ntid, NULL, mycp, (void *)&tmp);
        if(err != 0)
        {
            perror("pthread_create");
            exit(1);
        }
        percent = (double)tmp.progress * 100 / n;
        printf("%2.2f%c ", percent, '%');
    }
    printf("success !\n");

}

int main(int argc, char *argv[])
{
   course_cp(atoi(argv[1]));

   return 0;
}


