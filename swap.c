#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of swap command in the script
 *
 * Return: 0 on success, 1 on error.
 */
int swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if ((stack == NULL) || ((*stack)->next == NULL))
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		return (1);
	}
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
	return (0);
}
