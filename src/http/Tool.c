#include "Web.h"


int serverSocketInit() {
    //初始化和构造套接字
    WORD versionRequested;
    WSADATA wsaData;
    SOCKET serverSock;
    struct sockaddr_in serverAddress;
    int result;

    versionRequested = MAKEWORD(2, 2);
    if (WSAStartup(versionRequested, &wsaData) != 0) {
        printf("Failed to load Winsock!\n");
        system("pause");
        return -1;
    }
    printf("Succeed to load Winsock!\n");

    /* 创建套接字 */
    serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSock == INVALID_SOCKET) {
        printf("Failed to create socket!\n");
        system("pause");
        exit(1);
    }
    printf("Succeed to create socket!\n");

    /* 配置服务器IP、端口信息 */
    memset(&serverAddress, 0, sizeof(struct sockaddr));    //每一个字节都用0来填充
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP_ADDR);

    /* 绑定 */
    result = bind(serverSock, (SOCKADDR*)&serverAddress, sizeof(struct sockaddr));
    if (result == SOCKET_ERROR) {
        printf("Failed to bind stream socket!\n");
        system("pause");
        exit(1);
    }
    printf("Succeed to bind stream socket!\n");

    return serverSock;
}

int logo() {
    //Web服务器标志信息
    printf("___________________________________________________________\n");
    printf("  __          ________ _______\n");
    printf("  \\ \\        / /  ____|  _____\\\n");
    printf("   \\ \\  /\\  / /| |____  |____) )\n");
    printf("    \\ \\/  \\/ / |  ____|  ____(   __  __     __ ___\n");
    printf("     \\  /\\  /  | |____  |____) )(__ |_ \\  /|_ |___)\n");
    printf("      \\/  \\/   |______|_______/  __)|__ \\/ |__|   \\\n");
    printf("\n");
    printf("      Welcome to use the VolunteerManagementSystem!\n");
    printf("           开发人员： 罗俊杰   程阳   杨正阳\n");
    printf("___________________________________________________________\n\n");

    return OK;
}

