#include "monty.h"

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

/**
 * pallop - Prints all elements that was done by pushop.
 * @stack: Pointer to our doubly linked list struct.
 * @line_number: Line number in file.
 */
void pallop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;

	new = *stack;

	if (*stack != NULL)
	{
		while (new != NULL)
		{
			printf("%d\n", new->n);
			new = new->next;
		}
	}

}
