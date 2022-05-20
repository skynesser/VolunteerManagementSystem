#include "Web.h"

void sendFile(int socket,  char *URI) {

    //200 OK响应

     char* File_ok_line = "HTTP/1.1 200 OK\r\n";
     char* File_ok_type = "";
     char* File_ok_length = "Content-Length: ";
     char* File_ok_end = "\r\n";

    FILE* file;
    struct stat file_stat;
    char Length[BUF_SIZE];
    char sendBuf[BUF_SIZE];
    int send_length;

    if (judgeFileType(URI) == ERROR) {
        printf("The request file's type from client's request message is error!\n");
    }

    file = fopen(URI, "rb");
    if (file != NULL) {
        fstat(fileno(file), &file_stat);
        itoa(file_stat.st_size, Length, 10);

        if (sendInfo(socket, File_ok_line, strlen(File_ok_line)) == ERROR) {
            printf("Sending file_ok_line error!\n");
        }


        File_ok_type = judgeFileType(URI);
        if (sendInfo(socket, File_ok_type, strlen(File_ok_type)) == ERROR) {
            printf("Sending file_ok_type error!\n");
        }

        if (sendInfo(socket, File_ok_length, strlen(File_ok_length)) != ERROR) {
            if (sendInfo(socket, Length, strlen(Length)) != ERROR) {
                if (sendInfo(socket, "\n", 1) == ERROR) {
                    printf("Sending file_ok_length error!\n");
                }
            }
        }

        if (sendInfo(socket, File_ok_end, strlen(File_ok_end)) == ERROR) {
            printf("Sending file_ok_end error!\n");
        }

        while (file_stat.st_size > 0) {
            if (file_stat.st_size < 1024) {
                send_length = fread(sendBuf, 1, file_stat.st_size, file);
                if (sendInfo(socket, sendBuf, send_length) == ERROR) {
                    printf("Sending file information error!\n");
                    continue;
                }
                file_stat.st_size = 0;
            }
            else {
                send_length = fread(sendBuf, 1, 1024, file);
                if (sendInfo(socket, sendBuf, send_length) == ERROR) {
                    printf("Sending file information error!\n");
                    continue;
                }
                file_stat.st_size -= 1024;
            }
        }
    }
    else {
        printf("The file is NULL!\n");
    }

}


 char* judgeFileType( char *URI) {
    //文件类型判断
     char* suffix;

    if ((suffix = strrchr(URI, '.')) != NULL)
        suffix = suffix + 1;

    if (strcmp(suffix, "json") == 0) {
        return "Content-type: application/json\r\n";
    }
    else if (strcmp(suffix, "html") == 0) {
        return "Content-type: text/html\r\n";
    }
    else if (strcmp(suffix, "txt") == 0) {
        return "Content-type: text/plain\r\n";
    }
    else
        return ERROR;
}


int sendInfo(int Socket,  char* sendBuf, int Length) {
    //发送信息到客户端
    int sendTotal = 0, bufLeft, result = 0;

    bufLeft = Length;
    while (sendTotal < Length) {
        result = send(Socket, sendBuf + sendTotal, bufLeft, 0);
        if (result < 0) {
            break;
        }
        sendTotal += result;
        bufLeft -= result;
    }


    return result < 0 ? ERROR : OK;
}

