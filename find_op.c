#include "monty.h"

void find_op(char *token_cmd, unsigned int line_number)
{
	int i = 0;
	instruction_t op[] = {
		{"push", pushop},
		{NULL, NULL}
		};

	while (op[i].opcode != NULL)
	{
		if (strcmp(token_cmd, op[i].opcode) != 0)
		{
			printf("L<%d>: unknown instruction <%s>\n", line_number, token_cmd);
			exit(EXIT_FAILURE);
		}

		else if (strcmp(op[i].opcode, "push") == 0)
			printf("1\n");
		else
			printf("2\n");
		i++;
	}
}

void pushop()
{
}

void pushtest(char *line)
{
	char *token;
	token = strtok(line, DELIM);
	printf("%s", token);
}
