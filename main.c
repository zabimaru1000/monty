#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	unsigned int line_number = 1;
	int num;
	char *line;
	char *token;
	char *integer;
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
		token = strtok(line, DELIM);

		if (token == NULL)
			continue;
		printf("%s", token);

                /*if (strcmp(token, "push") == 0)
			/*call on push function*/
		/*printf("test");*/

		token = strtok(NULL, DELIM);

		if (token == NULL)
			break;
		/*use num as argument for push function*/
		num = atoi(token);
		printf("%d", num);
		if (strcmp(token, itoa(num, integer, 10)) == 0)
			printf("test");


		line_number++;
		putchar('\n');
	}

	putchar('\n');

	fclose(file);

	return (EXIT_SUCCESS);
}
