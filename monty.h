#ifndef _MONTY_H
#define _MONTY_H
#include <stdio.h>
extern struct stack_s *stack2;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, int val);
} instruction_t;


/*FUNCTIONS*/
void main_interpreter(
		char *line_buffer, int buffer_lenght, unsigned int line_number, FILE *file);
int *space_needed(char *line_buffer, int buffer_lenght);
int skip_spaces(char *buffer, int current_position, int limit);

char **get_command_str_list(
		char *line_buffer, int buffer_lenght, int *space_needed, FILE *file);
void malloc_err1(char *buffer1, char *buffer2, FILE *file);
int main_map(
		unsigned int line_number, char **list,  int *space_needed, FILE *file);
void EXIT_PROTOCOL(char **list, unsigned int line_number, FILE *file);
void EXIT_PROTOCOL2(char **list, unsigned int line_number, FILE *file);
int atoi_modified(char **list, unsigned int line_number, FILE *file);
void free_list_on_err(char **list);
void free_stack(void);
/*UPCODE FUNCTIONS*/
void push_UPCODE(stack_t **stack, unsigned int line_number, int val);
void pall_UPCODE(stack_t **stack, unsigned int line_number, int val);
void pint_UPCODE(stack_t **stack, unsigned int line_number, int val);
void pop_UPCODE(stack_t **stack, unsigned int line_number, int val);
void swap_UPCODE(stack_t **stack, unsigned int line_number, int val);
void add_UPCODE(stack_t **stack, unsigned int line_number, int val);
void nop_UPCODE(stack_t **stack, unsigned int line_number, int val);

#endif /*_MONTY_H*/
