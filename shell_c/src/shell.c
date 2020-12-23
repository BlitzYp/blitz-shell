#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "../headers/input.h"

#define EXIT_STATUS "exit"

int main()
{
    printf("\n*****BLITZ SHELL*****\n\n");
    sleep(1);
    while (1)
    {
        printf("%s:>>> ", getenv("USER"));
        char* line = malloc(sizeof(char) * 255);
        read_line(line);
        char** args = parse(line);
        pid_t id;
        if ((id = fork()) != 0) wait( NULL );
        else if (id < 0)
        {
            fprintf(stderr, "***ERROR***\nFailed to fork a new process!\n");
            exit(1);
        }
        else 
        {
            execvp(args[0], args);
            exit(0);
        }
        if (strcmp(args[0], EXIT_STATUS) == 0) break;
        free(line);
        free(args);
    }   
}
