#include "shell.h"

int (*builtin_f[]) (char **) = { &help, &cd};

/* char *builtin[] = { "help", "cd"}; */

/**
  *Fork -  wrapper function for fork.
  *Return: process created.
  */

pid_t Fork(void)
{
	pid_t pid = fork();

	if (pid < 0)
		perror("Fork error");
	return (pid);
}

/**
 * num - Calculates the number of builtin functions
 * @built: array of builtin commands
 * Return: the number of builtin functions
 */

int num(char *built[])
{
	return (sizeof(built) / sizeof(char *));
}
/**
 * help - Writes simple_shell instructions to stdout
 * @tokens: command
 *
 * Return: 1
 */

int help(char __attribute__((unused)) **tokens)
{
	write(STDOUT_FILENO, "simple shell\n", 14);
	return (1);
}

/**
 * exit_1 - Compares command with exit
 * @tokens: command
 *
 * Return: zero on success and 1 on failure
 */

int exit_1(char **tokens)
{
	if (!_strcmp(tokens[0], "exit"))
		return (0);

	return (1);
}

/**
 * cd - executes cd command
 * @tokens: command
 *
 * Return: zero on success
 */

int cd(char **tokens)
{
	int x, count;

	char __attribute__((unused)) *dir;
	char *delims = "=";
	char *buf = NULL, path_name[] = "HOME", **path_tokens = NULL;
	size_t size = 0;
	char *path = getpath(path_name);

	count = ntokens(path, delims);
	path_tokens = tokenise(count, path, delims);

	if (tokens[1] == NULL)
	{
		chdir(path_tokens[1]);
		free_dptr(path_tokens);
		return (0);
	}
	else
	{
		dir = getcwd(buf, size);
		x = (chdir(tokens[1]));
		if (x == -1)
		{
			perror("Error");
			free_dptr(path_tokens);
			return (0);

		}
		free_dptr(path_tokens);
	}

	return (0);

}

/**
 * compare - compares user input with the existing builtin commands
 * @tokens: user command
 *
 * Return: zero on success
 */

int compare(char **tokens)
{

	int i;
	char *builtin[] = { "help", "cd"};
	int size = num(builtin);

	if (tokens == NULL)
		return (-1);

	for (i = 0; i <= size; i++)
	{
		if (_strcmp(tokens[0], builtin[i]) == 0)
		{
			(*builtin_f[i])(tokens);
			return (1);
		}
	}
	return (0);
}

/**
 * def_prompt - write $ on a new line.
 *
 * Return: void.
 */

void def_prompt(void)
{
	write(1, "$ ", 2);
}

/**
 * def_prompt2 - Write > on a new line
 *
 * Return: void
 */

void def_prompt2(void)
{
	write(STDOUT_FILENO, "> ", 2);
}
