#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *add_UPCODE- add the two top elements and print the result
 *@stack: the stack
 *@line_number: the line number the programe is curentlly reading
 *@val: the value of the node (NOT USED)
 */
void add_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	unsigned long int result = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		result += (*stack)->n;
		result += (*stack)->next->n;
		printf("%ld\n", result);
	}
	val = val;
}
