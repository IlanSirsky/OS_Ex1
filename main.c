#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "shell.h"



int main(){
    char in[100];
    curr_dir();
    scanf("%[^\n]%*c", in);
    int len = strlen(in);
    //printf("%s\n", in);

    while(strcmp(in,"EXIT")){
         if (strncmp(in, "ECHO", 4) == 0)
        {
             for (int i = 5; i < len; i++)
            {
                printf("%c", in[i]);
            }

            printf("\n");
        }
        else if (strncmp(in, "TCP PORT", 8) == 0)
        {

        }
        else if (strncmp(in, "DIR", 3) == 0)
        {

        }
        else if (strncmp(in, "CD", 2) == 0)
        {

        }
        else if (strncmp(in, "COPY", 4) == 0)
        {

        }
        else if (strncmp(in, "DELETE", 6) == 0)
        {

        }
        bzero(in, 50);
        scanf("%[^\n]%*c", in);
    }
    printf("Bye\n");
    return 0;
}