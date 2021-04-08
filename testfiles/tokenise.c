#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - entry point, program starts here
 * @argc: Number of arguments
 * @argv: argument vector
 * Return: zero
 */

int main(int argc, char **argv)
{
	char *str;
	char *tok;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s string delim", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (str = argv[1]; ; str = NULL)
	{
		tok = strtok(str, argv[2]);
		if (tok == NULL)
			break;
		printf("%s\n", tok);
	}

	return (0);
}
