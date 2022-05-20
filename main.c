#include "http/Web.h"


int main() {
    //实现主要功能
    SOCKET ServerSock, MessageSock;
    struct sockaddr_in ClientAddr;
    int rval, Length;
    char revbuf[BUF_SIZE];

    logo();
    printf("Web Server 1.0 is starting......\n\n");
    ServerSock = serverSocketInit();
    printf("\n-----------------------------------------------------------\n");

    while (OK) {
        /* 启动监听 */
        rval = listen(ServerSock, BACKLOG);
        if (rval == SOCKET_ERROR) {
            printf("Failed to listen socket!\n");
            system("pause");
            exit(1);
        }
        printf("Listening the socket ......\n");

        /* 接受客户端请求建立连接 */
        Length = sizeof(struct sockaddr);
        MessageSock = accept(ServerSock, (SOCKADDR*)&ClientAddr, &Length);
        if (MessageSock == INVALID_SOCKET) {
            printf("Failed to accept connection from client!\n");
            system("pause");
            exit(1);
        }
        printf("Succeed to accept connection from [%s:%d] !\n\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

        /* 接收客户端请求数据 */
        memset(revbuf, 0, BUF_SIZE);    //每一个字节都用0来填充
        rval = recv(MessageSock, revbuf, BUF_SIZE, 0);
        revbuf[rval] = 0x00;
        if (rval <= 0)
            printf("Failed to receive request message from client!\n");
        else {
            printf("%s\n", revbuf); //输出请求数据内容
            handleRequestMessage(revbuf, MessageSock);
        }

        closesocket(MessageSock);
        printf("\n-----------------------------------------------------------\n");
    }

    closesocket(ServerSock);    //关闭套接字
    WSACleanup();   //停止Winsock

    return OK;
}

