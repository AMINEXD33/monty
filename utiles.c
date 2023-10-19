#include "monty.h"
#include <stdlib.h>
/**
*free_stack-free the stack
*/
void free_stack(void)
{
	struct stack_s *head = stack2;
	struct stack_s *prv = NULL;

	while (head != NULL)
	{
		prv = head;
		head = head->next;
		free(prv);
	}
	stack2 = NULL;
}
