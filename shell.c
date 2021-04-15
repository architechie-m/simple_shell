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
						sum += i, print_err(argv[0], sum, tokens[0]);
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
 * print_err - prints out error to standard output
 * @argv: argument vector
 * @sum: sum of commands passed by the user
 * @tokens: User command
 * Return: void
 */

void print_err(char *argv, int sum, char *tokens)
{
	write(STDOUT_FILENO, argv, (_strlen(argv)));
	write(STDOUT_FILENO, ": ", 2);
	print_number(sum);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, tokens, (_strlen(tokens) + 1));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found", 9);
}
