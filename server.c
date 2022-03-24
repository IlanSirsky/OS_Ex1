#include "shell.h"

#define IP "127.0.0.1"
#define SERVER_PORT 5060

void server()
{
    int listeningSocket = -1;  
    if((listeningSocket = socket(AF_INET , SOCK_STREAM , 0 )) == -1)
    {
        printf("Could not create listening socket : %d", errno);
        return;
    }

    struct sockaddr_in serverAddress, clientAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(IP);
    serverAddress.sin_port = htons(SERVER_PORT);  //network order

    
    // Bind the socket to the port with any IP at this port
    if (bind(listeningSocket, (struct sockaddr *)&serverAddress , sizeof(serverAddress)) == -1)
    {
        printf("Bind failed with error code : %d",errno);
        return ;
    }
    printf("Bind() success\n");
  
    // Make the socket listening; actually mother of all client sockets.
    if (listen(listeningSocket, 5) == -1) //5 is a Maximum size of queue connection requests
											//number of concurrent connections 
    {
	    printf("listen() failed with error code : %d" ,errno);
        return;
    }
    printf("Waiting for incoming TCP-connections...\n");
    
    socklen_t clientAddressLen = sizeof(clientAddress);
    char buffer[1024];
    int flag = 1;
    while (1)
    {
        if (flag)
        {
            clientAddressLen = sizeof(clientAddress);
            client_sock = accept(listeningSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
            printf("A new client connection accepted\n");
            flag = 0;
        }
        bzero(buffer, 1024);
        if (!recv(client_sock, buffer, sizeof(buffer), 0))
        {
            close(client_sock);
            flag = 1;
        }
        else
        {
            printf("%s\n", buffer);
        }
    }
}

int main(int argc, char const *argv[])
{
    server();
    return 0;
}