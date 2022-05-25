#include "Volunteer.h"

#define N 1000

static int tr[N][26],cnt[N],idx;

int mapVolunteerToInt(char *src){
    initTrie();
    return query(src,strlen(src));
//    printf("%s %d\n",src,query(src,strlen(src)));
//    if(strcmp(src,"name")==0){
//        return 0;
//    }else if(strcmp(src,"age")==0){
//        return 1;
//    }else if(strcmp(src,"sex")==0){
//        return 2;
//    }else if(strcmp(src,"contactNumber")==0){
//        return 3;
//    }else if(strcmp(src,"socialSecurityNumber")==0){
//        return 4;
//    }else if(strcmp(src,"unitInfo")==0){
//        return 5;
//    }else if(strcmp(src,"foreignLanguage")==0){
//        return 6;
//    }else if(strcmp(src,"foreignLanguageMastery")==0){
//        return 7;
//    }else if(strcmp(src,"isVolunteered")==0){
//        return 8;
//    }else if(strcmp(src,"volunteerTime")==0){
//        return 9;
//    }else{
//        return -1;
//    }
}

char *mapVolunteerToString(int type){
    if(type == 0){
        return "name";
    }else if(type == 1){
        return "age";
    }else if(type == 2){
        return "sex";
    }else if(type == 3){
        return "contactNumber";
    }else if(type == 4){
        return "socialSecurityNumber";
    }else if(type == 5){
        return "unitInfo";
    }else if(type == 6){
        return "foreignLanguage";
    }else if(type == 7){
        return "foreignLanguageMastery";
    }else if(type == 8){
        return "isVolunteered";
    }else if(type == 9){
        return "volunteerTime";
    }else{
        return "";
    }

}

int mapRaceToInt(char *src){
    initTrie();
    return query(src,strlen(src));
//    printf("%s %d\n",src,query(src,strlen(src)));
//    if(strcmp("raceName",src) == 0){
//        return 0;
//    }else if(strcmp("raceData",src) == 0){
//        return 1;
//    }else if(strcmp("raceCountry",src) == 0){
//        return 2;
//    }else if(strcmp("raceMAXPerson",src) == 0){
//        return 3;
//    }else{
//        return -1;
//    }
}

char *mapStringRaceToInt(int type){
    if(type == 0){
        return "raceName";
    }else if(type == 1){
        return "raceData";
    }else if(type == 2){
        return "raceCountry";
    }else if(type == 3){
        return "raceMAXPerson";
    }else{
        return "";
    }
}

int map(char *src){
    int num = 0;
    for(char *p = src ; *p != '\0' ; p++){
        num *= 10;
        num += (*p - '0');
    }
    return num;
}

void insert(char *src,int len,int val){
    int p = 0;
    for(int i = 0 ; i < len ; i++){
        int temp = src[i] > 'Z' ? src[i] - 'a' : src[i] - 'A';
        if(!tr[p][temp]){
            tr[p][temp] = ++idx;
        }
        p = tr[p][temp];
    }

    cnt[p] = val;
}

int query(char *src,int len){
    int p = 0;

    for(int i = 0 ; i < len ; i++){
        int temp = src[i] > 'Z' ? src[i] - 'a' : src[i] - 'A';
        if(!tr[p][temp]){
            return -1;
        }
        p = tr[p][temp];
    }

    return cnt[p];
}

void initTrie(){
    if(idx == 0){
        FILE *fp = fopen("../src/Trie.txt","r");
        char s[MAX];
        int val;
        for(int i = 0 ; i < TYPE + RACE ; i++){
            fscanf(fp,"%s%d",s,&val);
            insert(s,strlen(s),val);
        }
        fclose(fp);
    }
}