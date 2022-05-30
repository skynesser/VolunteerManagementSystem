#include<stdio.h>
#include<string.h>

#define MAXLENGTH 100
#define MAX 250
#define TYPE 10
#define RACE 4


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




