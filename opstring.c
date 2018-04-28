#include "monty.h"

/**
 * parse - Splits a line into tokens to specify a command and a argument.
 * @line: One line of an external file contained in a string
 * @stack: Our struct that contains a doubly linked list representing the stack
 * @line_number: An integer that keeps track of the line number in file.
 */
void parse(char *line, stack_t **stack, unsigned int line_number)
{
	char *token;
	int num;

	token = strtok(line, DELIM);

	if (strcmp(token, "push") == 0)
	{
		num = atoi(strtok(NULL, DELIM));
		pushop(stack, line_number, num);
	}

	else
	{
		find_op(stack, line_number, token);
	}
}

/**
 * find_op - Uses a tokenized string from line to find a function to use.
 * @stack: Pointer to doubly linked list struct, stack_t
 * @line_number: Line number in file
 * @token: Tokenized string without space, newline, or integer.
 */
void find_op(stack_t **stack, unsigned int line_number, char *token)
{
	int i = 0;
	instruction_t op[] = {
		{"pall", pallop},
		{NULL, NULL}
	};

	while (op[i].opcode != NULL)
	{
		if (strcmp(token, op[i].opcode) != 0)
		{
			printf("L%d: unknown instruction %s\n",
			       line_number, token);

			exit(EXIT_FAILURE);
		}

		else
			op[i].f(stack, line_number);

		i++;
	}

}
