#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int course, course1, course2;

    course = fork();
    if(course < 0)
    {
        perror("fork");
        exit(-1);
    }
    if(course > 0)
    {
        printf("parent\n");
        course1 = fork();
        if(course1 < 0)
        {
            perror("fork");
            exit(-1);
        }
        if(course1 > 0)
        {
            while(1)
            {
                sleep(1);
                printf("parent---1\n");
                wait();
            }
        }
        if(course1 == 0)
        {
            while(1)
            {
                sleep(1);
                printf("child---1\n");
            }
        }
    }
    if(course == 0)
    {
        printf("child\n");
        course2 = fork();
        if(course2 < 0)
        {
            perror("fork sourse2");
            exit(-1);
        }
        if(course2 > 0)
        {
            while(1)
            {
                sleep(1);
                printf("child---parent\n");
            }
        }
        if(course2 == 0)
        {
            while(1)
            {
                sleep(1);
                //printf("child---child\n");
                execl("hello", "hello", NULL);
            }
        }
    }

    return 0;
}
