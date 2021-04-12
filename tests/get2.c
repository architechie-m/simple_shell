#include "shell.h"

extern char **environ;

/**
  *getpath - get path of argument
  */

char *getpath(char **cmd)
{
	char *wd;
	int count;
	int i, j, k;
	char **tokens = NULL;
	char path[] = "PATH";
	int len = strlen(path);
	char delims[] = {"=:"};
	char *path2 = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (k = 0; k < len; k++)
		{
			if (environ[i][k] != path[k])
			{
				break;
			}
		}
		if (k == len && environ[i][k] == '=')
		{
			printf("%s", environ[i]);
			path2 = environ[i];
		}
	}
	count = ntokens(path2, delims);
	tokens = tokenise(count, path2, delims);
	j = 1;
	while (tokens[j] != NULL)
	{
		wd = strcat(tokens[j], cmd[0]);
		execve(wd, cmd, environ);

		j++;		
	}


	wait(NULL);
	free(wd);
	return (0);



}
