#include "Web.h"

void Post(char *URI,char* message,int socket) {
    if(strcmp(URI,"/") == 0){

        URI = "../src/volunteerInfo.txt";

        sendFile(socket,URI);

        //获取客户端POST请求方式的值
        const char* suffix;

        if ((suffix = strrchr(message, '\n')) != NULL)
            suffix = suffix + 1;

        printf("\n\nPost Value: %s\n\n", suffix);

        FILE *fp = fopen("../src/volunteerInfo.txt","a");

        fprintf(fp,"%s\n",suffix);

        fclose(fp);

        assign();
    }else{
        printf("不存在请求路径");
    }


}
