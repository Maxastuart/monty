#include "monty.h"

/**
 * push_q - pushes a new node to dlistint_t as if it were a queue, on bottom
 * @stack: pointer to the head of the stack
 * @line_number: unused
 *
 * Return: 0 on success, 1 on error.
 */
int push_q(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new, *temp;
	char *val, *delim = "\n \a\t\0";
	int i;

	val = strtok(NULL, delim);
	if ((val == NULL) ||
	    ((val[0] != '+') && (val[0] != '-') && (isdigit(val[0]) == 0)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (1);
	}
	for (i = 1; val[i]; i++)
	{
		if (isdigit(val[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
			return (1);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (1);
	}
	new->n = atoi(val);
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		temp = *stack;
		while (temp->prev != NULL)
			temp = temp->prev;
		temp->prev = new;
		new->next = temp;
	}
	return (0);
}
