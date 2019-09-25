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
	int temp;

	if (*stack == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		return (1);
	}
	if ((*stack)->prev == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		return (1);
	}

	temp = (*stack)->n;
	(*stack)->n = ((*stack)->prev)->n;
	((*stack)->prev)->n = temp;

	return (0);
}
