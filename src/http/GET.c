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
    }else if(strcmp(URI,"/race") == 0){
        URI = "../src/volunteerRequest.txt";
        handleRaceValue(value);
        sendFile(socket,URI);
    }else if(strcmp(URI,"/age") == 0){
        URI = "../src/volunteerRequest.txt";
        handleAgeValue(value);
        sendFile(socket,URI);
    }else{
        printf("不存在请求路径");
    }
}

void handleValue(char *value){
   struct Volunteer volunteers[MAX];
   char racesName[MAX][MAXLENGTH];
   int volunteerLength;
   int raceLength;

    volunteerLength = findVolunteer(volunteers);



    if(value!=NULL){
        volunteerLength = selectVolunteer(volunteers, volunteerLength, value);
    }


    FILE *fp = fopen("../src/VolunteerRequest.txt","w");

    fprintf(fp,"volunteerRequest('[");

    for(int i = 0 ; i < volunteerLength ; i++){
        fprintf(fp,"{");

        for(int j = 0 ; j < TYPE ; j++){
            fprintf(fp, "\\\"%s\\\":\\\"%s\\\"", mapVolunteerToString(j), volunteers[i].field[j]);
//            if(j != TYPE - 1)
                fprintf(fp,",");
        }

        raceLength = findRaceByName(racesName,volunteers[i].field[name]);

        fprintf(fp,"\\\"race\\\":[");

        for(int k = 0 ; k < raceLength ; k++){
            fprintf(fp,"\\\"%s\\\"",racesName[k]);
            if(k != raceLength - 1){
                fprintf(fp,",");
            }
        }

        fprintf(fp,"]");

        fprintf(fp,"}");

        if(i != volunteerLength - 1){
            fprintf(fp,",");
        }


    }



    fprintf(fp,"]')");

    fclose(fp);

}

void handleRaceValue(char *value){
    struct Race races[MAX];

    char volunteersName[MAX][MAXLENGTH];

    int raceLength,volunteerLength;

    raceLength = findRace(races);

    if(value != NULL){
        raceLength = selectRace(races, raceLength, value);
    }

    volunteerLength = findNameByRace(volunteersName,races[0].field[raceName]);

    FILE *fp = fopen("../src/VolunteerRequest.txt","w");

    fprintf(fp,"volunteerRequest('{\\\"volunteer\\\":[");



    for(int i = 0 ; i < volunteerLength ; i++){
        fprintf(fp,"\\\"%s\\\"",volunteersName[i]);

        if(i != volunteerLength - 1){
            fprintf(fp,",");
        }
    }


    fprintf(fp,"]}')");

    fclose(fp);



}

void handleAgeValue(char *value){
    struct Volunteer volunteers[MAX];
    int volunteerLength;

    volunteerLength = findVolunteer(volunteers);

    int min,max,flag = 0,idx = 0;
    char s[MAX];

    for(char *p = value ; *p != '\0' ; p++){
        if(*p == '='){
            flag = 1;
        }else if(*p == '~'){
            s[idx] = '\0';
            idx = 0;
            min = map(s);
        }else if(flag){
            s[idx++] = *p;
        }
    }
    s[idx] = '\0';
    max = map(s);

    int index[MAX];
    idx = 0;

    for(int i = 0 ; i < volunteerLength ; i++){
        int volunteerAge = map(volunteers[i].field[age]);
        if(volunteerAge >= min && volunteerAge <= max){
            index[idx++] = i;
        }
    }

    for(int i = 0 ; i < idx ; i++){
        volunteers[i] = volunteers[index[i]];
    }

    volunteerLength = idx;

    FILE *fp = fopen("../src/VolunteerRequest.txt","w");

    fprintf(fp,"volunteerRequest('[");

    for(int i = 0 ; i < volunteerLength ; i++){
        fprintf(fp,"{");

        for(int j = 0 ; j < TYPE ; j++){
            fprintf(fp, "\\\"%s\\\":\\\"%s\\\"", mapVolunteerToString(j), volunteers[i].field[j]);
            if(j != TYPE - 1){
                fprintf(fp,",");
            }
        }

        fprintf(fp,"}");

        if(i != volunteerLength - 1){
            fprintf(fp,",");
        }


    }



    fprintf(fp,"]')");

    fclose(fp);

}








