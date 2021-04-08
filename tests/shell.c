#include "holberton.h"
/**
  * main - UNIX command line interpreter.
  * @argc: argument count.
  * @argv: argument vector.
  *
  * Return: 0.
  */
int main(int argc, char **argv)
{
	char *line, *token;
	int j;
	size_t len = 0;

	(void)argc;
	while (1)
	{
		def_prompt();
		while (getline(&line, &len, stdin) != -1)
		{
			token = strtok(line, " ");
			j = 1;
			if (token != NULL)
				argv[j] = token;
			if (execve(argv[j], argv, NULL) == -1)
			{
				write(1, argv[0], 6);
				write(1, ": No such file or Directory\n", 29);
				break;
			}
		}
	}
	free(line);
	free(token);
	free(argv[j]);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
  *def_prompt - write $ on a new line.
  *
  *Return: void.
  */
void def_prompt(void)
{
	write(1, "hello@mus:~$ ", 14);
}

/**
  *tokenise - break string into different parts
  *@str: string to be split.
  *@delims: where to break the string.
  *
  *Return: array of strings.
  */
char **tokenise(char *str, *
