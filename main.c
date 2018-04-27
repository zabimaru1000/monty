#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	unsigned int line_number = 1;
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;

	if (ac != 2)
	{
		printf("USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file <%s>\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_bytes = getline(&line, &len, file)) != -1)
	{
		parse(line, line_number);
		line_number++;
	}


	fclose(file);
	return (EXIT_SUCCESS);
}
