#define SERVER_IP_ADDR "127.0.0.1"  //服务器IP地址
#define SERVER_PORT 80              //服务器端口号
#define BACKLOG 10
#define BUF_SIZE 1024
#define OK 1
#define ERROR 0

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <winsock2.h>
#include <io.h>
#include "..\volunteer\Volunteer.h"
#pragma comment(lib,"ws2_32.lib")

int logo();
int serverSocketInit();
char* handleURI(char *URI,char *file);

int sendInfo(int socket,  char* sendBuf, int length);
void sendFile(int socket,  char *URI);
char* judgeFileType( char* URI);

void handleRequestMessage(char* message, int socket);

void Get(char *URI,int socket);

void Post(char *URI,char *message,int socket);

void handleValue(char *value);



