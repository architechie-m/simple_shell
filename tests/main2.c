#include "shell.h"

int main(int __attribute__((unused))argc,  char **argv)
{
	int count, i;
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
		if (strcmp(tokens[0], "exit\n") == 0)
			break;
		if (tokens[0] == '\0' || strcmp(tokens, "\n") == 0)
		{
			continue;
		}
		pid = Fork();
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				i = 0;
				while (count >= 0)
				{
					free(tokens[i]);
					count--;
					i++;
				}
				free(tokens);
				free(line);
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
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
