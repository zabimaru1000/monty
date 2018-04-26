#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	char *line;
	char *token;
	char *numtok;
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
		printf("Error: Can't open file <%s>\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_bytes = getline(&line, &len, file)) != -1)
	{
		/*token = push\0push\0push\0pall\0 */
		token = strtok(line, DELIM);

		printf("%s", token);

		/*if we encounter NULL, get to the 1st space, continue loop*/
		if (token == NULL)
			continue;

		/*tokenize with elements replaced by NULL*/
		numtok = strtok(NULL, DELIM);

		/*numtok is all numbers: 123, with \0 in between each*/
		/*if we reach (null), break loop*/
		if (numtok == NULL)
			break;

		/*print both token and numtok is the entire file without \n*/
		printf("%s", numtok);
	}

	putchar('\n');
	fclose(file);

	return (EXIT_SUCCESS);
}
