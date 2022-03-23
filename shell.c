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
        perror("getcwd() error");
        exit(1);
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

void dir_files()
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d == NULL)
    {
        printf("ERROR: Unknown directory!");
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
