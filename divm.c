#include "monty.h"

/**
 * divm - divides the 2nd top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_number: line number of div command in the script
 *
 * Return: 0 on success, 1 on error.
 */
int divm(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		printf("L%d: can't div, stack too short\n", line_number);
		return (1);
	}
	((*stack)->next)->n /= (*stack)->n;
	((*stack)->next)->prev = NULL;
	*stack = (*stack)->next;
	free(temp);
	return (0);
}
