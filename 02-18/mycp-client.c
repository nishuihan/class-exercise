#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_PORT 20000
#define CLIENT_SIZE 20
#define BUFFER_SIZE 100 

char buffer[BUFFER_SIZE];

int main(int argc, const char *argv[])
{
    
    int n, buffer_num;
    int client_socket;
    socklen_t server_len;
    struct sockaddr_in server;
    int flag = 1;

    int fd;
    //char *addr;

    if((fd = open("22222", O_RDWR | O_CREAT, 0777)) == -1)
    {
        perror("open");
        exit(-1);
    }
    //addr = mmap(0, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);



    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }
    else
        printf("socket success!\n");

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    server_len = sizeof(server);
    if(connect(client_socket, (struct sockaddr *)&server, server_len ) < 0)
    {
        perror("connect");
        exit(1);
    }
    else
        printf("connect success!\n");

    while(1)
    {
        //if(flag == 0)
        //{
        //n = write(STDOUT_FILENO, "> ", 3);
        //send(client_socket, argv[2], sizeof(argv[2]), 0);
        //flag = 0;
        //}
        //read(fd, buffer, BUFFER_SIZE);
        //if ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
        //{
        //n = send(client_socket, buffer, len, 0);
        //}

        //if(buffer[0] == '.')
        //break;
        //
        if((buffer_num = recv(client_socket, buffer, BUFFER_SIZE, 0)) == BUFFER_SIZE)
        {
            write(fd, buffer, BUFFER_SIZE);
        }
        else
        {
            write(fd, buffer, buffer_num);
            printf("cope success\n");
            break;
        }
    }
    
    close(client_socket);
    return 0;
}
