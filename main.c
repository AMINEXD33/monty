#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
*main-Entry Point
*Return: 1 always
*/
int main(int argc, char **argv)
{
    unsigned long int line = 0;
    unsigned int line_number = 1;
    char *line_buffer = NULL;
    int buffer_lenght = 0;
    FILE *file = NULL;
    struct stack_s *stack = NULL;

    stack = malloc(sizeof(int));
    if (stack == NULL)
    {
        dprintf(2,"Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    if (argc != 2)
    {
        dprintf(2,"USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    /*read from the specified file passed by the user*/
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        dprintf(2,"Error: Can't open file %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
        

    while ((buffer_lenght = getline(&line_buffer, &line, file)) != -1)
    {
        main_interpreter(line_buffer, buffer_lenght, line_number, stack);
        line_number++;
    }

    fclose(file);
    if (line_buffer)
        free(line_buffer);
    free(stack);

    return (EXIT_SUCCESS);
}