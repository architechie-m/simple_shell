#include "shell.h"

int main(int __attribute__((unused))argc,  char **argv)
{
	int count;
	size_t len = 0;
	char *line = NULL;
	pid_t pid;
	char **tokens;/* create an array of tokens from the split tokens, and allocate some memory*/
	char *delims = " , \n\t\r;";
	while (1)
	{
		def_prompt();

		if (getline(&line, &len, stdin) == -1)
			break;

		count = ntokens(line, delims);

		tokens = tokenise(count, line, delims);


		pid = Fork();
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				free(tokens);
				free(line);
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
			exit(0);
		}

		else
			wait(NULL);


	}
	free(tokens);
	free(line);
	exit(EXIT_SUCCESS);
}
/**
 *def_prompt - write $ on a new line.
 *
 *Return: void.
 */
void def_prompt(void)
{
	write(1, "hello@mus:~$ ", 14);
}
