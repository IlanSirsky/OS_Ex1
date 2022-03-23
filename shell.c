#include "shell.h"

void curr_dir()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("%s: ", cwd);
    }
    else
    {
        perror("getcwd() error\n");
        exit(1);
    }
}

void dir_files()
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d == NULL)
    {
        printf("ERROR: Unknown directory!\n");
        return;
    }
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

/*
The chdir command is a system function (system call) which is used to change the current working directory.
On some systems, this command is used as an alias for the shell command cd.
chdir changes the current working directory of the calling process to the directory specified in path.
*/
void changeCD(char in[], int len)
{
    char temp[len - 2];
    for (int i = 3; i < len; i++)
    {
        temp[i - 3] = in[i];
    }
    temp[len - 3] = '\0';
    chdir(temp);
}

/*
In our function we are using fwrite, fread and fopen
they all are library functions
*/
void copyFile(char *in, int len){
    char srcFile[50], dstFile[50];
    bzero(srcFile, 50);
    bzero(dstFile, 50);
    int flag = 0, j = 0;
    for (int i = 5; i < len; i++){
        if (flag == 0){
            if(in[i] == ' '){
                flag = 1;
                j = 0;
                continue;
            }
            srcFile[j] = in[i];
        }
        else {
            dstFile[j] = in[i];
        }
    }
    if (srcFile == NULL || dstFile == NULL){
        printf("Error: invalid src or dst\n");
        return;
    }
    char c;
    FILE *fSrc = fopen(srcFile, "r");
    FILE *fDst = fopen(dstFile, "a");
    while (c = fgetc(fSrc) != EOF) {
        fputc(c, fDst);
    }
    printf("Finished copying the file\n")
    fclose(fSrc);
    fclose(fDst);
}