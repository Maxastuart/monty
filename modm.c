#include "monty.h"

/**
 * modm - gets the remainder of the 2nd stack element divided by the top one
 * @stack: pointer to the stack
 * @line_number: line number of mod command in the script
 *
 * Return: 0 on success, 1 on error.
 */
int modm(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		return (1);
	}
	if ((*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		return (1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		return (1);
	}

	temp = *stack;
	((*stack)->prev)->n %= (*stack)->n;
	((*stack)->prev)->next = NULL;
	*stack = (*stack)->prev;
	free(temp);

	return (0);
}
