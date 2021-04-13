#include "shell.h"
/**
 * getpath - gets the PATH, splits it and appends user's command line to it
 * @cmd: Command passed by the user
 * @argv: command line argument, to be used to print out error when command
 * execution fails
 * Return: Zero upon success
 */

char *getpath(void)
{
	int i, k;
	char path[] = "PATH";
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


int build_exec(char **cmd, char **argv)
{
	char *wd;
	int count, i, j;
	char delims[] = {"=:"};
	char **tokens = NULL, *temp;
	char *path2 = (getpath());
	count = ntokens(path2, delims);
	tokens = tokenise(count, path2, delims);
	j = 1;

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
		j++;
	}
	if (!tokens[j] && i == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 3);
		perror(cmd[0]);
		free(temp);
		free_dptr(tokens);
		return (-1);
	}
	free_dptr(tokens);
	free(temp);
	return (0);
}
