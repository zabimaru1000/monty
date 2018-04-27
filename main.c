#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;
	unsigned int line_number = 1;
	char *line;
	char *token_cmd;
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
		token_cmd = strtok(line, DELIM);

		/*if (token_cmd == NULL)
		  continue;*/

                /*if (strcmp(token, "push") == 0)
			call on push function
		printf("test");*/

		/*integer = strtok(NULL, DELIM);

		if (integer == NULL)
		break;*/
		/*use num as argument for push function*/

		find_op(token_cmd, line_number);
		line_number++;
	}


	fclose(file);

	return (EXIT_SUCCESS);
}
