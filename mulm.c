#include "monty.h"

/**
 * mulm - multiplies the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of mul command in the script
 *
 * Return: 0 on success, 1 on error.
 */
int mulm(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		return (1);
	}
	if ((*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		return (1);
	}

	temp = *stack;
	((*stack)->prev)->n *= (*stack)->n;
	((*stack)->prev)->next = NULL;
	*stack = (*stack)->prev;
	free(temp);

	return (0);
}
