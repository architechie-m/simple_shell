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
	int count;
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
		if (builtin(tokens) == 1)
		{
			pid = Fork();
			if (pid == 0)
			{
				if (getpath(tokens, argv) == -1)
					break;
			}
			else
				wait(NULL);
		}
		else
			break;

		free(line), free_dptr(tokens);
	}
	free_dptr(tokens);
	free(line);
	exit(EXIT_SUCCESS);
}
