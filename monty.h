#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int goto_func(char *opcode, stack_t **top, unsigned int line_number);

void free_list(stack_t *head);

int push(stack_t **stack, unsigned int line_number);

int pall(stack_t **stack, unsigned int line_number);

int pint(stack_t **stack, unsigned int line_number);

int pop(stack_t **stack, unsigned int line_number);

int swap(stack_t **stack, unsigned int line_number);

int addm(stack_t **stack, unsigned int line_number);

int nop(stack_t **stack, unsigned int line_number);

int subm(stack_t **stack, unsigned int line_number);

int divm(stack_t **stack, unsigned int line_number);

int mulm(stack_t **stack, unsigned int line_number);

int modm(stack_t **stack, unsigned int line_number);

#endif /* __MONTY__ */
