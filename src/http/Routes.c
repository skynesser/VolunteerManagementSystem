#include "Web.h"




void handleRequestMessage(char* message, int socket) {

    char method[BUF_SIZE];
    char URI[BUF_SIZE];
    char version[BUF_SIZE];

    if (sscanf(message, "%s %s %s", method, URI, version) != 3) {
        printf("Request line error!\n");

    }   //提取"请求方法"、"URI"、"HTTP版本"三个关键要素

    printf("%s %s %s\n",method,URI,version);

    if (strcmp(method, "GET") == 0) {
        Get(URI,socket);
    }
    else if (strcmp(method, "POST") == 0) {
        Post(URI,message,socket);
    }
    else
        printf("请求方法错误");
}