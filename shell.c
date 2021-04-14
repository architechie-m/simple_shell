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
	char **tokens;
	char *delims = " ,\n\t\r;";
	char *line = NULL;

	signal(SIGINT, inthandler);

	while (1)
	{
		def_prompt(), line = read_line();

		count = ntokens(line, delims);
		tokens = tokenise(count, line, delims);
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

						sum = sum + i;
						write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
						write(STDOUT_FILENO, ": ", 2);
						print_number(sum);
						write(STDOUT_FILENO, ": ", 2);
						write(STDOUT_FILENO, tokens[0], _strlen(tokens[0]));
						write(STDOUT_FILENO, ": ", 2);
						write(STDOUT_FILENO, "not found\n", 10);
						i++;
						break;
					}
				}
				else
					wait(NULL);
			}
		}
		else
			break;
		i++;
		free(line), free_dptr(tokens);
	}
	free(line);
	exit(EXIT_SUCCESS);
}
