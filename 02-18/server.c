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

char buff[BUFFER_SIZE];

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server, client;
    socklen_t client_len;
    struct in_addr in;
    char c;
    int i, n, len;
    
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(-1);
    }
    else
        printf("server socket success!\n");

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = ntohs(INADDR_ANY);

    if(bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind");
        exit(-1);
    }
    else
        printf("bind sucess!\n");

    if(listen(server_socket, 5) < 0)
    {
        perror("listen\n");
        exit(-1);
    }
    else
        printf("listen success !\n");
    while(1)
    {
        client_len = sizeof(client);
        if((client_socket = accept(server_socket, (struct sockaddr *)&client, &client_len)) < 0)
        {
            close(client_socket);
            perror("accept\n");
            exit(-1);
        }
        else
        {
            printf("accept success !\n");
            in.s_addr = client.sin_addr.s_addr;
            printf("client ip is %s \n", inet_ntoa(in));
            printf("client port is %d \n", ntohs(client.sin_port));
        }
        while((len = recv(client_socket, buff, BUFFER_SIZE, 0)) > 0)
        {
            printf("%s", buff);
            //n = send(client_socket, buff, len, 0);
        }

        close(client_socket);
    }
    close(server_socket);
    
    return 0;
}
