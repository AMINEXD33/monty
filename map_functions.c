#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*main_map- maps eatch command to its correct handling function
*@line_number: the line number in wich the progrogramme is reading
*@space_needed: a list of lenght 2 , representing the space needed
*@file: the opened file
*@list: the list containing the command and arg
*the command and the arg
*Return:1 always
*/
int main_map(
		unsigned int line_number, char **list,  int *space_needed, FILE *file)
{
	int number = 0;
	int i;
	int has_arg[3] = {1, 0, 0};
	instruction_t map[] = {
		{"push", push_UPCODE},
		{"pall", pall_UPCODE},
		{"pint", pint_UPCODE},
	};

	for (i = 0; i < 3; i++)
	{
		if (strcmp(map[i].opcode, list[0]) == 0)
		{
			/*check if it needs an arg*/
			if (has_arg[i] == 1)
			{
				number = atoi_modified(list, line_number, file);
				map[i].f(&stack2, line_number, number);
			}
			else
				map[i].f(&stack2, line_number, 0);
			return (1);
		}
	}
	if (space_needed[0] != 1 && space_needed[1] != 1)
		EXIT_PROTOCOL2(list, line_number, file);
	return (1);
}
/**
*free_list_on_err- free the list, on error
*@list: the list array
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
*@line_number: the line number in wich the progrogramme is reading
*@file: the opened file
*@list: the list containing the command and its arg
*Return: the converted int value
*/
int atoi_modified(
		char **list, unsigned int line_number, FILE *file)
{
	unsigned long int x;

	x = 0;
	if (list[1][0] == '\0')
		EXIT_PROTOCOL(list, line_number, file);
	while (x < strlen(list[1]) - 1)
	{
		/*exit if a char is not in the range of numeric or not + or -*/
		if ((list[1][x] < '0' || list[1][x] > '9')
				&& (list[1][x] != '+' && list[1][x] != '-'))
		{
			EXIT_PROTOCOL(list, line_number, file);
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
*@line_number: the line number in wich the progrogramme is reading
*@list: the list containing the command and its arg
*@file: the opened file
*/
void EXIT_PROTOCOL(
		char **list, unsigned int line_number, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, list[1]);
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
	if (stack2 != NULL)
		free(stack2);
	/*close file*/
	if (file != NULL)
		free_stack();
	exit(EXIT_FAILURE);
}
/**
*EXIT_PROTOCOL- free the list and stack and print an error,
*directed at the command, then exit
*@line_number: the line number in wich the progrogramme is reading
*@list: the list containing the command and its arg
*@file: the opened file
*/
void EXIT_PROTOCOL2(
		char **list, unsigned int line_number, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, list[0]);
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
	if (stack2 != NULL)
		free_stack();
	/*close file*/
	if (file != NULL)
		fclose(file);
	exit(EXIT_FAILURE);
}
