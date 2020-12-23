#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LINE_LEN 255

void read_line(char* restrict dest)
{
    char buff[MAX_LINE_LEN];

    if (buff == NULL) 
    {
        fprintf(stderr, "Failed to allocate memory");
        exit(1);
    }
    int c;
    uint8_t pos = 0;
    while (1)
    {
        c = getchar();
        if (c == '\n')
        {
            buff[pos] = '\0';
            break;
        }
        buff[pos++] = (char) c;
    }

    strcpy(dest, buff);
}

char** parse(char* restrict line)
{
    char** args = malloc(sizeof(char*) * 10);

    char* token = strtok(line, " ");
    args[0] = token;

    uint8_t i = 1;
    while (token != NULL)
    {
        token = strtok(NULL, " \n");
        args[i++] = token;
    }
    
    return args;
}

