#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
*main-Entry Point
*Return: 1 always
*/
struct stack_s *stack2;
int main(int argc, char **argv)
{
	unsigned int line_number = 1;
	char line_buffer[4090];
	FILE *file = NULL;

	stack2 = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	/*read from the specified file passed by the user*/
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_buffer, sizeof(line_buffer), file) != NULL)
	{
		main_interpreter(line_buffer, strlen(line_buffer), line_number, file);
		line_number++;
	}
	fclose(file);
	if (stack2 != NULL)
		free_stack();
	return (EXIT_SUCCESS);
}
