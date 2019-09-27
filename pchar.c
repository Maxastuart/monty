#include "monty.h"

/**
 * pchar - prints the ascii value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: the line number of pchar in the script
 *
 * Return: 0 on success, 1 on error.
 */
int pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
			line_number);
		return (1);
	}

	if (((*stack)->n < 0) || ((*stack)->n > 127))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
			line_number);
		return (1);
	}

	printf("%c\n", (*stack)->n);

	return (0);
}
