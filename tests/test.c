#include "holberton.h"


int main()
{
	char *argv[] = {"/bin/ls", NULL};
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Whaaaaaaaaaaaaaaaaaaaaaaaaaaaat no.: ");
		}
	return (0);
}
