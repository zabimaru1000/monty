#include "monty.h"

/**
 * main - Takes arguments from cmd line
 * @ac: Number of arguments
 * @av: Argument contained in string
 * Return: EXIT_SUCCESS if everything ran fine, or EXIT_FAILURE
 */
int main(int ac, char **av)
{
	stack_t *stack;
	FILE *file;
	unsigned int line_number = 1;
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_bytes = getline(&line, &len, file)) != -1)
	{
		parse(line, &stack, line_number);
		line_number++;
	}


	fclose(file);
	return (EXIT_SUCCESS);
}
