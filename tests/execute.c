#include "shell.h"

extern char **environ;

/**
  *execute - handle command passed.
  *@tokens: array of strings.
  *@argv: argument vector.
  *Return: void.
  */
void execute(char **tokens, char **argv)
{
	int i;
	char cmd[1024];
	int flag2 = 0, flag = 0;
/* make the getcwd a function*/
	for (i = 0; tokens[0] != '\0'; i++)
	{
		if (tokens[0][i] == cmd[i])
		{
			flag2 = 1;
		}
		else
		{
			_strcat(cmd, tokens[0]);
			flag = 1;
			break;
		}
	}
	if (flag2)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			free_dptr(tokens);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (flag)
	{
		if (execve(cmd, &tokens[0], environ) == -1)
		{
			free_dptr(tokens);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}

}
