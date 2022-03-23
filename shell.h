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

void curr_dir();
void dir_files();
void changeCD(char*, int);



#endif