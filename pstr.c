#include "monty.h"

/**
 * pstr - prints all the ascii values in the stack
 * @stack: pointer to the stack
 * @line_number: unused.
 *
 * Return: Always 0.
 */
int pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	while ((temp != NULL) && (temp->n > 0) && (temp->n < 128))
	{
		printf("%c", temp->n);
		temp = temp->prev;
	}

	printf("\n");

	return (0);
}
