#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "shell.h"

int main()
{
	int i;
	char *argv[] = {"/bin/ls", "-l", NULL};

	for (i = 0; i < 5; i++)
	{
		if (Fork() == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				exit(0);
			}
		}
		wait(NULL);
	}
	return (0);
}
