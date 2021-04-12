#include "shell.h"

extern char **environ;

/**
  *getpath - append path to command.
  */

int getpath(char **cmd, char **argv)
{
	char *wd;
	int count, i, j, k;
	char **tokens = NULL, path[] = "PATH";
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
		if (_strcmp(cmd[0], "exit") == 0)
			exit(0);
		if (cmd[0][0] == '/')
			wd = cmd[0];
		else
		{
		/*	_strcpy(slash, "/"); */
			_strcat(tokens[j], "/");
			wd = _strcat(tokens[j], cmd[0]);
		}
		i = execve(wd, cmd, environ);
		j++;		
	}
 	if (!tokens[j] && i == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		perror(cmd[0]);
		free_dptr(tokens);
	}
	return (0);
}
