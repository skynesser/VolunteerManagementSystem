#include "Volunteer.h"

int mapToInt(char *src){

    if(strcmp(src,"name")==0){
        return 0;
    }else if(strcmp(src,"age")==0){
        return 1;
    }else if(strcmp(src,"sex")==0){
        return 2;
    }else if(strcmp(src,"contactNumber")==0){
        return 3;
    }else if(strcmp(src,"socialSecurityNumber")==0){
        return 4;
    }else if(strcmp(src,"unitInfo")==0){
        return 5;
    }else if(strcmp(src,"foreignLanguage")==0){
        return 6;
    }else if(strcmp(src,"foreignLanguageMastery")==0){
        return 7;
    }else if(strcmp(src,"isVolunteered")==0){
        return 8;
    }else if(strcmp(src,"volunteerTime")==0){
        return 9;
    }else{
        return -1;
    }
}

char *mapToString(int type){
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