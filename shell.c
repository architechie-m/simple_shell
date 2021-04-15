#include "shell.h"
/**
  *main - simple unix command line interpreter.
  *@argc: argument count.
  *@argv: argument vector.
  *
  *Return: success.
  */
int main(int __attribute__((unused))argc,  char **argv)
{
	int count, i = 1, sum = 0;
	pid_t pid;
	char **tokens, *delims = " ,\n\t\r;", *line = NULL;
	size_t len = 0;
	FILE *fp = stdin;

	if (checkfd(fp, argv) == 1)
		exit(0);
	signal(SIGINT, inthandler);
	while (1)
	{
		def_prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		count = ntokens(line, delims), tokens = tokenise(count, line, delims);
		if (_strcmp(line, "\n") == 0)
			continue;
		if (exit_1(tokens) == 1)
		{
			if (compare(tokens) != 1)
			{
				pid = Fork();
				if (pid == 0)
				{
					if (build_exec(tokens) == -1)
					{
						p_err(argv[0], sum, i, tokens[0]);
						break;
					}
				}
				else
					wait(NULL);
			}
		}
		else
			free(line), free_dptr(tokens), exit(0);
		i++, free_dptr(tokens);
	}
	free(line);
	return (0);
}
/**
 * p_err - prints out error to standard output
 * @argv: argument vector
 * @sum: sum of commands passed by the user
 * @i: count.
 * @tokens: User command
 * Return: void
 */

void p_err(char *argv, int sum, int i, char *tokens)
{
	sum += i;
	write(STDOUT_FILENO, argv, (_strlen(argv)));
	write(STDOUT_FILENO, ": ", 2);
	print_number(sum);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens, (_strlen(tokens) + 1));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found", 9);
}

/**
  *checkfd - checks if file descriptor is an open file terminal
  *@fd: descriptor.
  *@argv: argument vector.
  *Return: 0.
  */
int checkfd(FILE *fd, char **argv)
{
	int j, k = 1, s = 0;
	pid_t pid1;
	char **tokens1, *delims1 = " ,\n\t\r;", *line1 = NULL;
	size_t len1 = 0;

	if (!isatty(fileno(fd)))
	{
		getline(&line1, &len1, stdin);
		j = ntokens(line1, delims1), tokens1 = tokenise(j, line1, delims1);
		if (exit_1(tokens1) == 1)
		{
			if (compare(tokens1) != 1)
			{
				pid1 = Fork();
				if (pid1 == 0)
				{
					if (build_exec(tokens1) == -1)
					{
						p_err(argv[0], s, k, tokens1[0]);
					}
				}
				else
					wait(NULL);
			}
		}
		free(line1), free_dptr(tokens1);
		return (1);
	}
	return (0);
}
