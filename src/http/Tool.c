#include "Web.h"


int serverSocketInit() {
    //��ʼ���͹����׽���
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

    /* �����׽��� */
    serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSock == INVALID_SOCKET) {
        printf("Failed to create socket!\n");
        system("pause");
        exit(1);
    }
    printf("Succeed to create socket!\n");

    /* ���÷�����IP���˿���Ϣ */
    memset(&serverAddress, 0, sizeof(struct sockaddr));    //ÿһ���ֽڶ���0�����
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP_ADDR);

    /* �� */
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
    //Web��������־��Ϣ
    printf("___________________________________________________________\n");
    printf("  __          ________ _______\n");
    printf("  \\ \\        / /  ____|  _____\\\n");
    printf("   \\ \\  /\\  / /| |____  |____) )\n");
    printf("    \\ \\/  \\/ / |  ____|  ____(   __  __     __ ___\n");
    printf("     \\  /\\  /  | |____  |____) )(__ |_ \\  /|_ |___)\n");
    printf("      \\/  \\/   |______|_______/  __)|__ \\/ |__|   \\\n");
    printf("\n");
    printf("      Welcome to use the VolunteerManagementSystem!\n");
    printf("           ������Ա�� �޿���   ����   ������\n");
    printf("___________________________________________________________\n\n");

    return OK;
}

