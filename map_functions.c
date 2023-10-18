#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*main_map- maps eatch command to its correct handling function
*@stack: the stack
*@line_number: the line number in wich the progrogramme is reading
*@space_needed: a list of lenght 2 , representing the space needed
*the command and the arg
*Return:1 always
*/
int main_map(struct stack_s *stack, 
unsigned int line_number, char **list,  int *space_needed)
{
    int number = 0;
    int i, found;
    int has_arg[2] = {1, 0};
    struct instruction_s map[] =
    {
        {"push", push_UPCODE},
        {"pall", pall_UPCODE},
    };
    found = 0;
    for (i = 0; i < 2; i++)
    {
        if (strcmp(map[i].opcode, list[0]) == 0)
        {
            /*check if it needs an arg*/
            if (has_arg[i] == 1)
            {
                number = atoi_modified(list, stack, line_number);
                printf("the NUMBER PASSED WITH COMMAND {%s}BY THE ARG IS %d\n", list[0],number);
            }
            else{
                printf("COMMAND %s needs no args\n",list[0]);
            }
            return (EXIT_SUCCESS);
        }
    }
    if (space_needed[0] != 1 && space_needed[1] != 1)
        EXIT_PROTOCOL2(list, stack, line_number);
    return(1);
}

/**
*free_list_on_err- free the list, on error
*@list: the list array
*@line_number: the line number in wich the progrogramme is reading
*@upcode: the upcode str
*/
void free_list_on_err(char **list)
{
    if (list != NULL)
    {
        if (list[0] != NULL)
            free(list[0]);
        if (list[1] != NULL)
            free(list[1]);
        free(list);
    }
}
/**
*atoi_modified- this function handles the problem with the atoi function
*in wich you cant tell, if it read 0 , or returned an error, this modified,
*function, takes care of error handling
*@stack: the stack (see monty.h)
*@line_number: the line number in wich the progrogramme is reading
*Return: the converted int value
*/
int atoi_modified(
    char **list, struct stack_s *stack, unsigned int line_number)
{
    int x;

    x = 0;
    if (list[1][0] == '\0')
        EXIT_PROTOCOL(list, stack, line_number);
    while (x < strlen(list[1]) - 1)
    {
        /*exit if a char is not in the range of numeric or not + or -*/
        if ((list[1][x] < '0' || list[1][x] > '9')
        && (list[1][x] != '+' && list[1][x] != '-'))
        {
            EXIT_PROTOCOL(list, stack, line_number);
        }
        /*if a numeric char is detected, break*/
        if (list[1][x] >= 48 && list[1][x] <= 57)
            break;
    }
    return (atoi(list[1]));
}
/**
*EXIT_PROTOCOL- free the list and stack and print an error,
*directed at the arg, then exit
*@stack: the stack
*@line_number: the line number in wich the progrogramme is reading
*/
void EXIT_PROTOCOL(
    char **list, struct stack_s *stack, unsigned int line_number)
{
    printf("L%d: unknown instruction %s\n", line_number,list[1]);
    /*free list*/
    if (list != NULL)
    {
        if (list[0] != NULL)
            free(list[0]);
        if (list[1] != NULL)
            free(list[1]);
        free(list);
    }
    /*free stack*/
    free(stack);
    exit(EXIT_FAILURE);
}
/**
*EXIT_PROTOCOL- free the list and stack and print an error,
*directed at the command, then exit
*@stack: the stack
*@line_number: the line number in wich the progrogramme is reading
*/
void EXIT_PROTOCOL2(
    char **list, struct stack_s *stack, unsigned int line_number)
{
    printf("L%d: unknown instruction %s\n", line_number,list[0]);
    /*free list*/
    if (list != NULL)
    {
        if (list[0] != NULL)
            free(list[0]);
        if (list[1] != NULL)
            free(list[1]);
        free(list);
    }
    /*free stack*/
    free(stack);
    exit(EXIT_FAILURE);
}