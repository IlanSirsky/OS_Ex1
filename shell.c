#include "shell.h"

void curr_dir(){
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("In directory: %s\n", cwd);
    }
    else
    {
        perror("getcwd() error");
        exit(1);
    }
}