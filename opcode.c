#include "monty.h"

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
