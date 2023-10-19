#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
*push_UPCODE-push a node of a val=X to the stack
*@stack: the stack
*@line_number: the line the programe is currentlly reading
*@val: the value of the new added node
*/
void push_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	struct stack_s *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed hre\n");
		if (stack2 != NULL)
			free_stack();
		exit(EXIT_FAILURE);
	}
	node->n = val;
	node->prev = NULL;
	if ((stack2) != NULL)
	{
		node->next = (*stack);
		(*stack)->prev = node;
	}
	else
		node->next = NULL;
	(*stack) = node;
	stack2 = *stack;
	line_number = line_number;
}
/**
*pall_UPCODE-print the stack nodes from top bottom
*@stack: the stack
*@line_number: the line the programe is currentlly reading
*@val: value of the node
*/
void pall_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	struct stack_s *top_node = *stack;

	while (top_node != NULL)
	{
		printf("%d\n", top_node->n);
		top_node = top_node->next;
	}
	line_number = line_number;
	val = val;
}
/**
*pint_UPCODE- print the head of the stack
*@stack: the stack
*@line_number:the line in wich the programme is currentlly
*reading
*@val: the val of a node (not used here)
*
*
*/
void pint_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	if ((*stack) != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	line_number = line_number;
	val = val;
}
/**
*pop_UPCODE- pop the element on the tope of the stack
*@stack: the stack
*@line_number: the number of the line the programe currentlly
*reading
*@val: the val of the node
*
*/
void pop_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	stack_t *node = (*stack);

	if ((*stack) != NULL)
	{
		stack2 = (*stack)->next;
		free(node);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*NOT USED*/
	line_number = line_number;
	val = val;

}
/**
 *swap_UPCODE- swap the values of the two node at the top of the stack
 *@stack: the stack
 *@line_number: the line in wich the programme is currentlly reading
 *@val: the val of the a node (not used)
 */
void swap_UPCODE(stack_t **stack, unsigned int line_number, int val)
{
	int tmp = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}


	val = val;
}
