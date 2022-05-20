#include "Web.h"



void Get(char *URI,int socket){
    char *value = NULL;
    char loc[MAX] = {'\0'};
    int idx = 0;
    for(char *p = URI ; *p != '\0' ; p++){
        if(*p == '?'){
            value = p + 1;
            break;
        }
        loc[idx++] = *p;
    }

    URI = loc;

    if(strcmp(URI,"/") == 0){
        URI = "../src/volunteerRequest.txt";
        handleValue(value);
        sendFile(socket,URI);
    }else{
        printf("不存在请求路径");
    }
}

void handleValue(char *value){
   struct Volunteer volunteers[MAX];
   int length;

   length = findVolunteer(volunteers);


    if(value!=NULL){
        length = selectVolunteer(volunteers,length,value);
    }


   for(int i = 0 ; i < length ; i++)
       for(int j = 0 ; j < TYPE ; j++){
           printf("%s ",volunteers[i].property[j]);
           if(j==TYPE-1){
               printf("\n");
           }
       }

   FILE *fp = fopen("../src/VolunteerRequest.txt","w");

    fprintf(fp,"volunteerRequest('[");

    for(int i = 0 ; i < length ; i++){
        fprintf(fp,"{");

        for(int j = 0 ; j < TYPE ; j++){
            fprintf(fp,"\\\"%s\\\":\\\"%s\\\"", mapToString(j),volunteers[i].property[j]);
            if(j != TYPE - 1){
                fprintf(fp,",");
            }
        }

        fprintf(fp,"}");
        if(i != length - 1){
            fprintf(fp,",");
        }
    }

    fprintf(fp,"]')");

    fclose(fp);

}










