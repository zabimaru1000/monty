#include "monty.h"

void opcode(char *lines)
{
	stack_t **stack;
	unsigned int line_number = 0;
	int i, j = 0;

	instruction_t op[] =
	{
		{"push", pushop},
		{"pall", pallop},
		{NULL, NULL}
	};

	stack = malloc(sizeof(stack_t));

	while (lines[i] != '\0')
	{
		while (op[j].opcode != NULL)
		{
			if (*op[j].opcode == lines[i])
				op[j].f(stack, line_number);
			j++;
		}

		i++;
	}
}
