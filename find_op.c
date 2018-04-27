#include "monty.h"

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
			printf("L<%d>: unknown instruction <%s>\n", line_number, token);
			exit(EXIT_FAILURE);
		}

		else
			op[i].f(stack, line_number);

		i++;
	}

	/*printf("%d -> %s\n", line_number, token);*/
}

void pallop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new = NULL;
	new = *stack;

	if ((*stack) == NULL)
	{
		return;
	}
	printf("test\n");
	while(new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
