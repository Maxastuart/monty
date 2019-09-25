#include "monty.h"

/**
 * push - pushes a new node to the dlistint_t stack
 * @stack: pointer to the head of the stack
 * @line_number: unused
 *
 * Return: 0 on success, 1 on error.
 */
int push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;
	char *val, *delim = "\n \a\t\0";
	int i;

	val = strtok(NULL, delim);
	if (val == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		return (1);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	for (i = 0; val[i]; i++)
	{
		if (isalpha(val[i]))
		{
			printf("L%d: usage: push integer\n", line_number);
			return (1);
		}
	}
	new->n = atoi(val);
	new->next = NULL;
	if (*stack == NULL)
		new->prev = NULL;
	else
	{
		new->prev = *stack;
		(*stack)->next = new;
	}
	*stack = new;
	return (0);
}
