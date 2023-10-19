#include "monty.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
*main_interpreter-a function that takes a buffer ,
*and parsse it for a command and its argument
*@line_buffer: the buffer that's holding the command and arg
*@buffer_lenght: the lenght of the line_buffer
*@line_number: the current line number the programe is reading from file
*@file: the opened file
*/
void main_interpreter(char *line_buffer, int buffer_lenght,
unsigned int line_number, FILE *file)
{
	int *space_needed_val = NULL;
	char **list = NULL;
	/*get space needed for the command and arg*/
	space_needed_val = space_needed(line_buffer, buffer_lenght);
	/*store the command and arg in an array of 2*/
	list = get_command_str_list
		(line_buffer, buffer_lenght, space_needed_val, file);
	/*map the command to its UPCODE function*/
	main_map(line_number, list, space_needed_val, file);
	/*free the two elements when done*/
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
*space_needed- this function simply count the number of bytes that are valid
*and returns the value to be allocated
*@line_buffer: the buffer that's holding the command and arg
*@buffer_lenght: the lenght of the line_buffer
*Return: 0 if no bytes are valid, N where N is the number of the needed memorie
*/
int *space_needed(char *line_buffer, int buffer_lenght)
{
	int x = 0;
	int command_bytes_needed = 0;
	int arg_bytes_needed = 0;
	static int array[2];
	int command_end = 0;

	/*ignore the spaces at the start of the line*/
	x = skip_spaces(line_buffer, x, buffer_lenght);
	/*get the spaces needed for the command and it's arg*/
	while (x < buffer_lenght)
	{
		if (line_buffer[x] == 32)
		{
			x = skip_spaces(line_buffer, x, buffer_lenght);
			command_end = 1;
		}
		if (((line_buffer[x] >= 48 && (line_buffer[x] <= 57))
					|| (line_buffer[x] >= 65 && line_buffer[x] <= 90)
					|| (line_buffer[x] >= 97 && line_buffer[x] <= 122)
					))
		{
			if (command_end == 0)
				command_bytes_needed++;
			else
				arg_bytes_needed++;
		}
		x++;
	}
	/*adding one for the null byte at the end of any str*/
	command_bytes_needed++;
	arg_bytes_needed++;
	/*assigning the vars to the array*/
	array[0] = command_bytes_needed;
	array[1] = arg_bytes_needed;
	return (array);
}
/**
*get_command_str_list-a function that gets the args from the line buffer
*and store it in an array of 2 , index(0) is the command , index(1) is the
*argument, and it returns the array of 2.
*@line_buffer: the buffet that contains the line from the file
*@buffer_lenght: the lenght of the buffer
*@space_needed: an array of lenght 2 of type int, contains the lenght needed
*to be allocated to store the argument and it's arg,
*(see space_needed function for more)
*@file: the opened file
*Return: The char list of lenght 2, containing the command and its argument
*/
char **get_command_str_list(
		char *line_buffer, int buffer_lenght, int *space_needed, FILE *file)
{
	int x = 0;
	int command_tracker = 0;
	int args_tracker = 0;
	int command_end = 0;
	static char **list;


	list = malloc(sizeof(char *) * 2);
	if (list == NULL)
		malloc_err1(NULL, NULL, file);
	list[0] = malloc(sizeof(char) * space_needed[0]);
	list[0][space_needed[0] - 1] = '\0';
	list[1] = malloc(sizeof(char) * space_needed[1]);
	list[1][space_needed[1] - 1] = '\0';
	if (list[0] == NULL || list[1] == NULL)
		malloc_err1(list[0], list[1], file);
	x = skip_spaces(line_buffer, x, buffer_lenght);
	while (x < buffer_lenght)
	{
		if (line_buffer[x] == 32)
		{
			x = skip_spaces(line_buffer, x, buffer_lenght);
			command_end = 1;
		}
		if (((line_buffer[x] >= 48 && line_buffer[x] <= 57)
					|| (line_buffer[x] >= 65 && line_buffer[x] <= 90)
					|| (line_buffer[x] >= 97 && line_buffer[x] <= 122)
					))
		{
			if (command_end == 0)
			{
				if (space_needed[0] > 1)
				{
					list[0][command_tracker] = line_buffer[x];
					command_tracker++;
				}
			}
			else
			{
				if (space_needed[1] > 1)
				{
					list[1][args_tracker] = line_buffer[x];
					args_tracker++;
				}
			}
		}
		x++;
	}
	return (list);
}
/**
*skip_spaces- skips spaces and return the position without spaces
*@buffer: the str
*@current_position: the current position to traverse from
*@limit: the size of the buffer
*Return: the position witout spaces
*/
int skip_spaces(char *buffer, int current_position, int limit)
{
	/*ignore the spaces at the start of the line*/
	while (current_position < limit)
	{
		if (buffer[current_position] != 32)
			break;
		current_position++;
	}
	return (current_position);
}
/**
*malloc_err1-this function takes care of handling any malloc errors
*of the two buffers in get_command_str_list
*@buffer1: a buffer
*@buffer2: a buffer
*@file: an open file
*/
void malloc_err1(char *buffer1, char *buffer2, FILE *file)
{
	fprintf(stderr, "Error: malloc failed\n");
	if (buffer1 != NULL)
		free(buffer1);
	if (buffer2 != NULL)
		free(buffer2);
	if (file != NULL)
		free(file);
	exit(EXIT_FAILURE);
}
