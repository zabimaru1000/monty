#include "monty.h"

void parse(char *line, unsigned int line_number)
{
	stack_t *stack;
	char *token;
	int num;

	stack = NULL;
	token = strtok(line, DELIM);

	if (strcmp(token, "push") == 0)
	{
		num = atoi(strtok(NULL, DELIM));
		pushop(&stack, line_number, num);
	}

	else
	{
		find_op(&stack, line_number, token);
	}
}

void pushop(stack_t **stack, unsigned int line_number __attribute__((unused)), int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = num;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	else
		new->next = NULL;

	new->prev = NULL;
	*stack = new;

	/*printf("[%d] -> %d\n", line_number, new->n);*/
}
