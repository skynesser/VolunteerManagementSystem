#include "Volunteer.h"


int findVolunteer(struct Volunteer volunteers[]) {
    FILE *fp = fopen("../src/volunteerInfo.txt", "r");
    int length = 0;
    while (!feof(fp)) {
        char temp[MAX], s[MAX];
        fscanf(fp, "%s", temp);
        int type, flag = 0, idx = 0;
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == '=') {
                s[idx] = '\0';
                flag = 1;
                type = mapVolunteerToInt(s);
                idx = 0;
            } else if (temp[i] == '&') {
                volunteers[length].field[type][idx] = '\0';
                flag = 0;
                idx = 0;
            } else if (!flag) {
                s[idx++] = temp[i];
            } else {
                volunteers[length].field[type][idx++] = temp[i];
            }
        }
        length++;
    }

    length--;
    fclose(fp);
    return length;
}

int selectVolunteer(struct Volunteer volunteers[], int length, char *condition) {
    int index[MAX], idx = 0, type;
    char standard[TYPE][MAXLENGTH];
    char s[MAX];

//    printf("%s\n", condition);

    memset(standard, 0, sizeof standard);

    for (char *p = condition; *p != '\0'; p++) {
        if (*p == '=') {
            s[idx] = '\0';
            type = mapVolunteerToInt(s);
            idx = 0;
        } else if (*p == '&') {
            s[idx] = '\0';
            for (int i = 0; i <= idx; i++) {
                standard[type][i] = s[i];
            }
            idx = 0;
        } else {
            s[idx++] = *p;
        }
    }

    s[idx] = '\0';

    strcpy(standard[type], s);

//    for (int i = 0; i < TYPE; i++) {
//        printf("type:%d %s\n", i, standard[i]);
//    }

    idx = 0;

    for (int i = 0; i < length; i++) {
        int flag = 1;
        for (int j = 0; j < TYPE; j++) {
            if (strlen(standard[j]) > 0) {
                if (strcmp(standard[j], volunteers[i].field[j]) != 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1) {
            index[idx++] = i;
        }
    }

    for (int i = 0; i < idx; i++) {
        volunteers[i] = volunteers[index[i]];
    }

    return idx;
}

int findRace(struct Race races[]) {
    FILE *fp = fopen("../src/raceInfo.txt", "r");
    int length = 0;
    while (!feof(fp)) {
        char temp[MAX], s[MAX];
        fscanf(fp, "%s", temp);
        int type,flag = 0,idx = 0;
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == '=') {
                s[idx] = '\0';
                flag = 1;
                type = mapRaceToInt(s);
                idx = 0;
            } else if (temp[i] == '&') {
                races[length].field[type][idx] = '\0';
                flag = 0;
                idx = 0;
            } else if (!flag) {
                s[idx++] = temp[i];
            } else {
                races[length].field[type][idx++] = temp[i];
            }
        }
        length++;
    }
    fclose(fp);
    return length;
}

int selectRace(struct Race races[],int length,char *condition){
    char standard[MAXLENGTH];

    int flag = 0,idx = 0;

    for(char *p = condition ; *p != '\0' ; p++){
        if(*p == '='){
            flag = 1;
        }else if(flag){
            standard[idx++] = *p;
        }
    }
    standard[idx] = '\0';


    for(int i = 0 ; i < length ; i++){
        if(strcmp(races[i].field[raceName], standard) == 0){
            races[0] = races[i];
            return 1;
        }
    }

    return 0;
}

int findRaceByName(char racesName[][MAXLENGTH],char *src){
    FILE *fp = fopen("../src/volunteerToRace.txt","r");

    int length = 0;


    while(!feof(fp)){
        char temp[MAX],s[MAX];
        fscanf(fp,"%s",temp);
        int flag = 0,idx = 0,i = 0;
        for(; temp[i] != '&' ; i++){
            if(temp[i] == '='){
                flag = 1;
            }else if(flag){
                s[idx++] = temp[i];
            }
        }

        s[idx] = '\0';
        flag = 0;
        idx = 0;

        if(strcmp(s,src) == 0){
            for(; temp[i] != '\0' ; i++){
                if(temp[i] == '='){
                    flag = 1;
                }else if(flag){
                    s[idx++] = temp[i];
                }
            }
        }

        if(flag){
            s[idx] = '\0';
            strcpy(racesName[length++],s);
        }
    }

    fclose(fp);
    return length;
}

int findNameByRace(char volunteersName[][MAXLENGTH],char *src){
    FILE *fp = fopen("../src/raceToVolunteer.txt","r");


    int length = 0;
    int flag = 0,idx = 0,i;
    char temp[MAX],s[MAX];


    while(!feof(fp)){
        fscanf(fp,"%s",temp);
        i = 0,flag = 0,idx = 0;
        for(; temp[i] != '&' ; i++){
            if(temp[i] == '='){
                flag = 1;
            }else if(flag){
                s[idx++] = temp[i];
            }
        }
        s[idx] = '\0';
        idx = 0;
        flag = 0;
        if(strcmp(s,src) == 0){
            for(; temp[i] != '\0' ; i++){
                if(temp[i] == '='){
                    flag = 1;
                }else if(temp[i] == ','){
                    s[idx] = '\0';
                    idx = 0;
                    strcpy(volunteersName[length++],s);
                }else if(flag){
                    s[idx++] = temp[i];
                }
            }
        }
    }

    s[idx] = '\0';
    strcpy(volunteersName[length++],s);

    fclose(fp);

    return length;
}
