#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *mod_UPCODE- get reminder of the top element by the second top element
 *, pop the top and
 *append the resuld to the new top element
 *@stack: the stack
 *@line_number: the line in wich the programe is reading
 *currentlly
 *@val: the value of the node
 */
void mod_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	int a = 0;
	int b = 0;
	stack_t *tmp = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*get vals*/
	b = (*stack)->n;
	a = (*stack)->next->n;
	if (b == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*remove top*/
	tmp = stack2;
	stack2 = stack2->next;
	free(tmp);
	/*divide result*/
	stack2->n = (a % b);
	val = val;
}
/**
 *add_UPCODE- print the char representation of the top element in stack
 *@stack: the stack
 *@line_number: the line number the programe is curentlly reading
 *@val: the value of the node (NOT USED)
 */
void pchar_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
        if ((*stack)->n < 0 || (*stack)->n > 127)
        {
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		    exit(EXIT_FAILURE);
        }
        else
        {
            printf("%c\n", (char)(*stack)->n);
        }
	}
	val = val;
}
/**
 *pstr_UPCODE- print the char representation of every node in the stack
 * top to bottom
 *@stack: the stack
 *@line_number: the line number the programe is curentlly reading
 *@val: the value of the node (NOT USED)
 */
void pstr_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
    stack_t *head = (*stack);
	if ((*stack) == NULL)
	{
        printf("\n");
        return;
	}
	else
	{
        while (head != NULL)
        {
            if (head->n <= 0 || head->n > 127)
            {
                return;
            }
            else
            {
                printf("%c", (char)head->n);
            }
            head = head->next;
        }
        printf("\n");
	}
	val = val;
    line_number = line_number;
}