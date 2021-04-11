#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

extern char **environ;
int main()
{
	char *wd;

	int count;
	int i, j, k;
	char **tokens = NULL;
	char path[] = "PATH";
	int len = strlen(path);
	char delims[] = {":"};
	char *path2 = NULL;
	char *buf = NULL;
	size_t n = 0;

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
	while (tokens[j] != NULL)
	{
		printf("%s\n", tokens[j]);
		j++;
	}


	wd = getcwd(buf, n);
	chdir(tokens[j - 1]);

	execve(tokens[j - 1], tokens, NULL);

	wait(NULL);
	free(wd);
	return (0);



}
