#include "Volunteer.h"


int findVolunteer(struct Volunteer volunteers[]){
    FILE *fp = fopen("../src/VolunteerInfo.txt","r");
    int length = 0;
    while(!feof(fp)){
        char temp[MAX],s[MAX];
        fscanf(fp,"%s",temp);
        int type,flag = 0,idx = 0;
        for(int i = 0 ; temp[i] != '\0' ; i++){
            if(temp[i]=='='){
                s[idx] = '\0';
                flag = 1;
                type = mapToInt(s);
                idx = 0;
            }else if(temp[i]=='&'){
                volunteers[length].property[type][idx] = '\0';
                flag = 0;
                idx = 0;
            }else if(!flag){
                s[idx++] = temp[i];
            }else{
                volunteers[length].property[type][idx++] = temp[i];
            }
        }
        length++;
    }
    length--;
    fclose(fp);
    return length;
}

int selectVolunteer(struct Volunteer volunteers[],int length,char *condition){
    int index[MAX],idx = 0,type;
    char standard[TYPE][MAXLENGTH];
    char s[MAX];

    printf("%s\n",condition);

    memset(standard,0,sizeof standard);

    for(char *p = condition ; *p != '\0' ; p++){
        if(*p == '='){
            s[idx] = '\0';
            type = mapToInt(s);
            idx = 0;
        }else if(*p == '&'){
            s[idx] = '\0';
            strcpy(standard[type],s);
        }else{
            s[idx++] = *p;
        }
    }

    s[idx] = '\0';

    strcpy(standard[type],s);

    idx = 0;

    for(int i = 0 ; i < length ; i++){
        int flag = 1;
        for(int j = 0 ; j < TYPE ; j++){
            if(strlen(standard[j]) > 0){
                if(strcmp(standard[j],volunteers[i].property[j])!=0){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1){
            index[idx++] = i;
        }
    }

    for(int i = 0 ; i < idx; i++){
        volunteers[i] = volunteers[index[i]];
    }

    return idx;
}

