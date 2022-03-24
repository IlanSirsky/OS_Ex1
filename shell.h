#ifndef shell
#define shell

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <errno.h>

int sock;
int client_sock;

void currDir();
void dirFiles();
void changeCD(char*, int);
void copyFile(char *, int);
void delFile(char *, int);

void client();
void server();

#endif