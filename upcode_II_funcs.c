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
/**
 *nop_UPCODE- this function does nothing
 *@stack: the stack
 *@line_number: the line in wich the programe is reading
 *currentlly
 *@val: the value of the node
 */
void nop_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	(*stack) = (*stack);
	line_number = line_number;
	val = val;
}
/**
 *sub_UPCODE- substract the top element by the second top element
 *, pop the top and
 *append the resuld to the new top element
 *@stack: the stack
 *@line_number: the line in wich the programe is reading
 *currentlly
 *@val: the value of the node
 */
void sub_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	int a = 0;
	int b = 0;
	stack_t *tmp = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*get vals*/
	a = (*stack)->n;
	b = (*stack)->next->n;
	printf("a = %d, b = %d\n", a, b);
	if (b == 0)
	{
		fprintf(stderr, "L%d: can't sub, devide by 0\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*remove top*/
	tmp = stack2;
	stack2 = stack2->next;
	free(tmp);
	/*add result*/
	stack2->n = (a / b);
	val = val;
}
