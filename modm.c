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
	stack_t *temp = *stack;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		return (1);
	}
	((*stack)->next)->n %= (*stack)->n;
	((*stack)->next)->prev = NULL;
	*stack = (*stack)->next;
	free(temp);
	return (0);
}
