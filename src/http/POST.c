#include "Web.h"

void Post(char *URI,char* message,int socket) {
    if(strcmp(URI,"/") == 0){

        URI = "../src/volunteerRequest.txt";

        //获取客户端POST请求方式的值
        const char* suffix;

        if ((suffix = strrchr(message, '\n')) != NULL)
            suffix = suffix + 1;

//        if(verifyForm(suffix) == 0){
//            sendFile(socket,URI);
//            return;
//        }

        FILE *fp = fopen("../src/volunteerRequest.txt","w");

        fprintf(fp,"submit successfully \r\n");

        fclose(fp);

        sendFile(socket,URI);

        printf("\n\nPost Value: %s\n\n", suffix);

        fp = fopen("../src/volunteerInfo.txt","a");

        fprintf(fp,"%s\n",suffix);

        fclose(fp);

        assign();
    }else{
        printf("不存在请求路径");
    }


}

int verifyForm(char *value){
    int len = strlen(value);

    int idx = 0,flag = OK,type;
    char s[MAX];

    for(int i = 0 ; i < len ; i++){
        if(value[i] == '='){
            s[idx] = '\0';
            type = mapVolunteerToInt(s);
            idx = 0;
        }else if(value[i] == '&'){
            s[idx] = '\0';
            idx = 0;
            if(verifyType(s,type) == ERROR){
                flag = ERROR;
            }
        }else{
            s[idx++] = value[i];
        }
    }
    s[idx] = '\0';
    if(verifyType(s,type) == ERROR){
        flag = ERROR;
    }

    return flag;
}
