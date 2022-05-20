#include "Web.h"

char *file = "/1.json";

void Get(char *URI,int socket){
    if(strcmp(URI,"/") == 0){
        URI = handleURL(URI);

        sendFile(socket,URI);
    }else{
        printf("不存在请求路径");
    }


}

char *handleURL(char *URL){
    char *URI = _pgmptr;

    char body[200] = {0};
    int flag = 0,idx = 0;

    for(char *p = URI ; *p != '\0' ; p++){
        if(strcmp(p,"\\cmake-build-debug\\VolunteerManagementSystem.exe")==0){
            break;
        }
        if(!flag&&*p=='\\'){
            flag = 1;
        }
        if(flag){
            if(*p == '\\'){
                body[idx++] = '/';
            }else{
                body[idx++] = *p;
            }
        }
    }

    char _URI[200] = {'\0'};

    int index = 0;

    for(char *p = body ; *p != '\0' ; p++){
        _URI[index++] = *p;
    }

    for(char *p = file ; *p != '\0' ; p++){
        _URI[index++] = *p;
    }

    _URI[index] = '\0';

    URL = _URI;
}



int inquireFile(char *URI) {
    struct stat File_info;

    if (stat(URI, &File_info) == -1)
        return ERROR;
    else{
        return File_info.st_size;
    }
}





