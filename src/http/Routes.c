#include "Web.h"




void handleRequestMessage(char* message, int socket) {

    char method[BUF_SIZE];
    char URI[BUF_SIZE];
    char version[BUF_SIZE];

    if (sscanf(message, "%s %s %s", method, URI, version) != 3) {
        printf("Request line error!\n");

    }   //��ȡ"���󷽷�"��"URI"��"HTTP�汾"�����ؼ�Ҫ��

    printf("%s %s %s\n",method,URI,version);

    if (strcmp(method, "GET") == 0) {
        Get(URI,socket);
    }
    else if (strcmp(method, "POST") == 0) {
        Post(URI,message,socket);
    }
    else
        printf("���󷽷�����");
}