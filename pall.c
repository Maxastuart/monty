#include "monty.h"

/**
 * pall - prints all the values in the stack
 * @stack: pointer to the stack
 * @line_number: unused.
 *
 * Return: 0 on success, 1 on error.
 */
int pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}
