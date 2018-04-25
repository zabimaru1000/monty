#include "monty.h"

int main(int ac, char **av)
{
	/*Declare lines to store each line in file in 2D array */
	/*Declare str to store text in string*/
	char (*lines)[MAX_CHAR];
	char *str;
	int i, j = 0;
	FILE *file;

	if (ac != 2)
	{
		printf("USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}

	/*Allocate required memory for max amount of lines and char in each*/
	lines = malloc(MAX_LINES * sizeof(*lines));
	file = fopen(av[1], "r");

	/*As long as we get a line & until we reach max lines*/
	/*Store each line in str. Also add 1 to str until we reach newline*/
	/*Append a null byte at the end of the line, add j by 1 for next line*/
	while (fgets(lines[j], MAX_CHAR, file) && j < MAX_LINES)
	{
		str = lines[j];

		while(*str && *str != '\n')
		{
			str++;
		}

		*str = '\0';
		j++;
	}

	/*test if each line is stored in an array*/
	/*as long as i is less than amount of lines, print each line*/
	for (i = 0; i < j; i++)
		printf("line[%d]: '%s'\n", i + 1, lines[i]);


	free(lines);

	fclose(file);

	return (EXIT_SUCCESS);
}
