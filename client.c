#include "shell.h"

#define IP "127.0.0.1"
#define SERVER_PORT 5060

void client()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        printf("Could not create socket : %d", errno);
    }
    struct sockaddr_in serverAddress;

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(IP);
    
    if (connect(sock, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1)
    {
	    printf("connect() failed with error code : %d", errno);
    }
    printf("Connected to server\n");
}