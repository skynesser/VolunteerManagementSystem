#include "Volunteer.h"




void assign(){
    int name = 0;
    int foreignLanguage = 6;
    int foreignLanguageMastery = 7;
    int isVolunteered = 8;
    int volunteerTime = 9;
    int raceName = 0;
    int raceData = 1;
    int raceCountry = 2;
    int raceMAXPerson = 3;

    struct Race races[MAX];
    struct Volunteer volunteers[MAX];
    struct RaceAssignment raceAssignment[MAX];

    int raceLength,volunteerLength;

    raceLength = findRace(races);

    volunteerLength = findVolunteer(volunteers);


    int suitability[raceLength][volunteerLength];

    memset(suitability,0,sizeof suitability);
    memset(raceAssignment,0,sizeof raceAssignment);

    for(int i = 0 ; i < raceLength ; i++)
        for(int j = 0 ; j < volunteerLength ; j++){
            if(strcmp(races[i].field[raceData], volunteers[j].field[volunteerTime]) == 0){
                if(strcmp(volunteers[j].field[isVolunteered],"yes") == 0){
                    suitability[i][j] += 2;
                }
                if(strcmp(races[i].field[raceCountry],volunteers[j].field[foreignLanguage]) == 0){
                    suitability[i][j] += map(volunteers[j].field[foreignLanguageMastery]);
                }
                suitability[i][j] += 1;
            }
        }

    for(int i = 0 ; i < raceLength ; i++)strcpy(raceAssignment[i].race,races[i].field[raceName]);

    for(int i = 0 ; i < volunteerLength ; i++){
        int index = -1;
        for(int j = 0 ; j < raceLength ; j++){
            if(map(races[j].field[raceMAXPerson]) == raceAssignment[j].person)continue;
            if(index == -1 && suitability[j][i]){
                index = j;
            }else if(suitability[j][i] > suitability[index][i]){
                index = j;
            }
        }
        if(index != -1){
               strcpy(raceAssignment[index].volunteer[raceAssignment[index].person++],volunteers[i].field[name]);

        }
    }

    FILE *fp = fopen("../src/raceToVolunteer.txt","w");
    FILE *fp2 = fopen("../src/volunteerToRace.txt","w");

    for(int i = 0 ; i < raceLength ; i++){
        fprintf(fp,"raceName=%s&volunteer=",raceAssignment[i].race);
        for(int j = 0 ; j < raceAssignment[i].person ; j++){
            if(j != 0)fprintf(fp,",");
            fprintf(fp,"%s",raceAssignment[i].volunteer[j]);

            fprintf(fp2,"name=%s&raceName=%s\n",raceAssignment[i].volunteer[j],raceAssignment[i].race);
        }
        fprintf(fp,"\n");
    }

    printf("assign over\n");

    fclose(fp);
    fclose(fp2);

}


