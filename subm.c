#include "monty.h"

/**
 * subm - subtracts the top stack element from the next one
 * @stack: pointer to the stack
 * @line_number: line number of sub command in the script
 *
 * Return: 0 on success, 1 on error.
 */
int subm(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		return (1);
	}
	if ((*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		return (1);
	}

	temp = *stack;
	((*stack)->prev)->n -= (*stack)->n;
	((*stack)->prev)->next = NULL;
	*stack = (*stack)->prev;
	free(temp);

	return (0);
}
