#include<stdio.h>
#include<string.h>

#define MAXLENGTH 100
#define MAX 200
#define TYPE 10

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

struct Volunteer{
    char property[TYPE][MAXLENGTH];
};

int findVolunteer(struct Volunteer volunteers[]);
int selectVolunteer(struct Volunteer volunteers[],int length,char* condition);
int mapToInt(char *src);
char *mapToString(int type);


