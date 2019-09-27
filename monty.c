#include "monty.h"

/**
 * main - opens and reads lines from the file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, -1 on error.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *opcode = NULL, *line = NULL, *delim = "\n \a\t\0";
	unsigned int fval, line_num = 0, q_mode = 0;
	size_t len = 0;
	ssize_t nread;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, file)) != -1)
	{
		line_num++;
		opcode = strtok(line, delim);
		if (opcode)
		{
			fval = goto_func(opcode, &top, line_num, q_mode);
			if (fval == 1)
			{
				free(line);
				fclose(file);
				free_list(top);
				exit(EXIT_FAILURE);
			}
			if (fval == 2)
				q_mode = 0;
			if (fval == 3)
				q_mode = 1;
		}
	}
	free(line);
	fclose(file);
	free_list(top);
	exit(EXIT_SUCCESS);
}


/**
 * goto_func - finds and executes functions from monty bytecode tokens
 * @opcode: string from the Monty ByteCode file (should be a command)
 * @top: pointer to a script
 * @line_number: line count from the file (for error reporting)
 * @q_mode: 0 if stack mode, 1 if queue mode
 *
 * Return: 0 on success, 1 on error, 2 on 'stack', 3 on 'queue'.
 */
int goto_func(char *opcode, stack_t **top, unsigned int line_number,
	      unsigned int q_mode)
{
	int i;
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", addm},
		{"nop", nop},
		{"sub", subm},
		{"div", divm},
		{"mul", mulm},
		{"mod", modm},
		{"pchar", pchar},
		{"pstr", pstr},
		{"\0", NULL}
	};
	if (opcode[0] == '#')
		return (0);
	else if (strcmp(opcode, "stack") == 0)
		return (2);
	else if (strcmp(opcode, "queue") == 0)
		return (3);
	else if (q_mode == 0)
		ins[0].f = push;
	else if (q_mode == 1)
		ins[0].f = push_q;
	for (i = 0; ins[i].f != NULL; i++)
		if (strcmp(opcode, ins[i].opcode) == 0)
			return (ins[i].f(top, line_number));

	fprintf(stderr, "L%d: unknown instruction %s\n",
	       line_number, opcode);

	return (1);
}

/**
 * free_list - frees a monty doubly-linked list stack
 * @head: pointer to the head node of the list
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->prev;
		free(head);
		head = temp;
	}
}
