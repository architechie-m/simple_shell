#include "shell.h"

extern char **environ;

/**
  *getpath - append pathi to command.
  */

int getpath(char **cmd, char **argv)
{
	char *wd;
	int count, i, j, k;
	char **tokens = NULL, path[] = "PATH", *temp;
	int len = _strlen(path);
	char delims[] = {"=:"}, *path2 = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (k = 0; k < len; k++)
		{
			if (environ[i][k] != path[k])
				break;
		}
		if (k == len && environ[i][k] == '=')
			path2 = environ[i];
	}
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
		write(STDERR_FILENO, ": ", 2);
		perror(cmd[0]);
		return (-1);
	}
	return (0);
}
