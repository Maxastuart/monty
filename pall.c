#include "monty.h"

/**
 * pall - prints all the values in the stack
 * @stack: pointer to the stack
 * @line_number: unused.
 *
 * Return: Always 0.
 */
int pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	return (0);
}
