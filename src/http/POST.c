#include "Web.h"

void Post(char *URI,char* message,int socket) {
    if(strcmp(URI,"/") == 0){

        URI = "../src/VolunteerInfo.txt";

        sendFile(socket,URI);

        //��ȡ�ͻ���POST����ʽ��ֵ
        const char* suffix;

        if ((suffix = strrchr(message, '\n')) != NULL)
            suffix = suffix + 1;

        printf("\n\nPost Value: %s\n\n", suffix);

        FILE *fp = fopen("../src/VolunteerInfo.txt","a");

        fprintf(fp,"%s\n",suffix);

        fclose(fp);
    }else{
        printf("����������·��");
    }


}
