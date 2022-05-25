#include<stdio.h>
#include<string.h>

#define MAXLENGTH 100
#define MAX 250
#define TYPE 10
#define RACE 4

#define name 0
#define age 1
#define sex 2
#define contactNumber 3
#define socialSecurityNumber 4
#define unitInfo 5
#define foreignLanguage 6
#define foreignLanguageMastery 7
#define isVolunteered 8
#define volunteerTime 9

#define raceName 0
#define raceData 1
#define raceCountry 2
#define raceMAXPerson 3



struct Volunteer{
    char field[TYPE][MAXLENGTH];
};

struct Race{
    char field[RACE][MAXLENGTH];
};

struct RaceAssignment{
    char volunteer[MAXLENGTH][10];
    char race[MAXLENGTH];
    int person;
};

int findVolunteer(struct Volunteer volunteers[]);
int findRace(struct Race races[]);
int findRaceByName(char racesName[][MAXLENGTH],char *src);
int findNameByRace(char volunteersName[][MAXLENGTH],char *src);
int selectVolunteer(struct Volunteer volunteers[],int length,char* condition);
int selectRace(struct Race races[],int length,char *condition);
int mapVolunteerToInt(char *src);
int mapRaceToInt(char *src);
int map(char *src);
char *mapVolunteerToString(int type);
char *mapRaceToString(int type);
int query(char *src,int len);
void insert(char *src,int len,int val);
void initTrie();
void assign();



