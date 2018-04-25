#include "monty.h"

void pushop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if (*stack == NULL)
		exit(EXIT_FAILURE);
	else
	{
		while (head->next != NULL)
			head = head->next;


		printf("%d\n", head->n);
		printf("%d\n", line_number);
	}

}

void pallop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	head = *stack;

        if (*stack == NULL)
                exit(EXIT_FAILURE);
        else
        {
                while (head->next != NULL)
                        head = head->next;


                printf("%d\n", head->n);
                printf("%d\n", line_number);
        }

}
