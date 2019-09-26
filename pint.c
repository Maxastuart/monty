#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: the line number of pint in the script
 *
 * Return: 0 on success, 1 on error.
 */
int pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (1);
	}
	printf("%d\n", (*stack)->n);
	return (0);
}
