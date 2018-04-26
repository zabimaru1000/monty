#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	char *line;
	char *token;
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
		token = strtok(line, DELIM)

		printf("%s", token);
	}

	fclose(file);

	return (EXIT_SUCCESS);
}
