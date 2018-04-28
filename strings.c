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
 * pushop - Adds an integer onto the stack by adding a node in list.
 * @stack: Pointer to our struct stack_t
 * @line_number: unused parameter
 * @num: An integer converted from a string containing the argument for push/
 */
void pushop(stack_t **stack, unsigned int line_number __attribute__((unused))
, int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	new->n = num;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}
