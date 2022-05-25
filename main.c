#include "src/http/Web.h"


int main() {

    SOCKET ServerSock, MessageSock;
    struct sockaddr_in ClientAddr;
    int result, Length;
    char revBuf[BUF_SIZE];

    logo();
    printf("Web Server 1.0 is starting......\n\n");
    ServerSock = serverSocketInit();
    printf("\n-----------------------------------------------------------\n");

    while (OK) {
        result = listen(ServerSock, BACKLOG);
        if (result == SOCKET_ERROR) {
            printf("Failed to listen socket!\n");
            system("pause");
            exit(1);
        }
        printf("Listening the socket ......\n");

        Length = sizeof(struct sockaddr);
        MessageSock = accept(ServerSock, (SOCKADDR*)&ClientAddr, &Length);
        if (MessageSock == INVALID_SOCKET) {
            printf("Failed to accept connection from client!\n");
            system("pause");
            exit(1);
        }
        printf("Succeed to accept connection from [%s:%d] !\n\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

        memset(revBuf, 0, BUF_SIZE);
        result = recv(MessageSock, revBuf, BUF_SIZE, 0);
        revBuf[result] = 0x00;
        if (result <= 0)
            printf("Failed to receive request message from client!\n");
        else {
            printf("%s\n", revBuf);
            handleRequestMessage(revBuf, MessageSock);
        }

        closesocket(MessageSock);
        printf("\n-----------------------------------------------------------\n");
    }

    closesocket(ServerSock);
    WSACleanup();

    return 0;
}

