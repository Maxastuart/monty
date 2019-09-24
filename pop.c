#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of pop command in the script
 *
 * Return: 0 on success, 1 on error.
 */
int pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		return (1);
	}
	temp->prev = NULL;
	free(*stack);
	*stack = temp;
	return (0);
}
