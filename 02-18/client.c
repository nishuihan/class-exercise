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

#define SERVER_PORT 20000
#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];

int main(int argc, const char *argv[])
{
    
    int n, len;
    int client_socket;
    socklen_t server_len;
    struct sockaddr_in server;

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
        n = write(STDOUT_FILENO, "> ", 3);
        if ((len = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
        {
            n = send(client_socket, buffer, len, 0);
        }

        if(buffer[0] == '.')
            break;

        if((len = recv(client_socket, buffer, len, 0)) > 0)
            n = write(STDOUT_FILENO, buffer, len);
    }
    
    close(client_socket);
    return 0;
}
