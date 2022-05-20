#include "http/Web.h"


int main() {
    //ʵ����Ҫ����
    SOCKET ServerSock, MessageSock;
    struct sockaddr_in ClientAddr;
    int rval, Length;
    char revbuf[BUF_SIZE];

    logo();
    printf("Web Server 1.0 is starting......\n\n");
    ServerSock = serverSocketInit();
    printf("\n-----------------------------------------------------------\n");

    while (OK) {
        /* �������� */
        rval = listen(ServerSock, BACKLOG);
        if (rval == SOCKET_ERROR) {
            printf("Failed to listen socket!\n");
            system("pause");
            exit(1);
        }
        printf("Listening the socket ......\n");

        /* ���ܿͻ������������� */
        Length = sizeof(struct sockaddr);
        MessageSock = accept(ServerSock, (SOCKADDR*)&ClientAddr, &Length);
        if (MessageSock == INVALID_SOCKET) {
            printf("Failed to accept connection from client!\n");
            system("pause");
            exit(1);
        }
        printf("Succeed to accept connection from [%s:%d] !\n\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

        /* ���տͻ����������� */
        memset(revbuf, 0, BUF_SIZE);    //ÿһ���ֽڶ���0�����
        rval = recv(MessageSock, revbuf, BUF_SIZE, 0);
        revbuf[rval] = 0x00;
        if (rval <= 0)
            printf("Failed to receive request message from client!\n");
        else {
            printf("%s\n", revbuf); //���������������
            handleRequestMessage(revbuf, MessageSock);
        }

        closesocket(MessageSock);
        printf("\n-----------------------------------------------------------\n");
    }

    closesocket(ServerSock);    //�ر��׽���
    WSACleanup();   //ֹͣWinsock

    return OK;
}

