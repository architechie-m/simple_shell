#include "shell.h"
/**
 * getpath -  finds PATH environment variable
 * @path: environment variable
 * Return: Returns PATH upo success
 */

char *getpath(char path[])
{
	int i, k;
	int len = _strlen(path);
	char *path2 = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (k = 0; k < len; k++)
			if (environ[i][k] != path[k])
				break;
		if (k == len && environ[i][k] == '=')
			path2 = environ[i];
	}
	return (path2);
}
/**
 * build_exec - builds path for a command and executes it
 * @cmd: command passed by the user
 * @argv: command line argument, to print out error when command
 * execution fails
 *
 * Return: Zero upon success
 */

int build_exec(char **cmd, char **argv)
{
	char path[] = "PATH";
	int count, i, j = 1;
	char *wd, delims[] = {"=:"};
	char *path2 = (getpath(path)), **tokens = NULL, *temp;

	count = ntokens(path2, delims);
	tokens = tokenise(count, path2, delims);
	while (tokens[j] != NULL)
	{
		if (cmd[0][0] == '/')
			wd = cmd[0];
		else
		{
			temp = malloc(sizeof(char *) *
				      (1 + sizeof(tokens[j]) +
				       sizeof(cmd[0])));
			if (temp == NULL)
			{
				free(temp);
				return (-1);
			}
			_strcpy(temp, tokens[j]);
			_strcat(temp, "/");
			wd = _strcat(temp, cmd[0]);
		}
		i = execve(wd, cmd, environ);
		if (i == -1 && cmd[0][0] != '/')
			free(temp);
		j++;
	}
	if (!tokens[j] && i == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 3);
		perror(cmd[0]);
		free_dptr(tokens);
		return (-1);
	}
	free_dptr(tokens), free(temp);
	return (0);
}
