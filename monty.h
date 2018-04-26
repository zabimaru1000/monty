#ifndef MONTY_H
#define MONTY_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define DELIM "\n\t\a\r"
#define MAX_CHAR 50
#define MAX_LINES 40

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(unsigned int line_number);
} instruction_t;

void pushop();
void pallop(/*stack_t **stack,*/ unsigned int line_number);
void pintop(/*stack_t **stack,*/ unsigned int line_number);
void popop(stack_t **stack, unsigned int line_number);
void swapop(stack_t **stack, unsigned int line_number);
void addop(stack_t **stack, unsigned int line_number);
void nopop(stack_t **stack, unsigned int line_number);
void opcode(char *lines);

#endif
