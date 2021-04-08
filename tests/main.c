#include "shell.h"

int main(int argc,  char **argv)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	char **tokens;
	/* create an array of tokens from the split tokens, and allocate some memory*/
	(void)argc;
	while (1)
	{
		def_prompt();
		if (getline(&line, &len, stdin) == -1)
			exit(EXIT_FAILURE);

		tokens = (char **)tokenise(line, " ,\n\t\r;");
		printf("%s\n", tokens[0]);
		pid = Fork();
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror(argv[0]);
			}
			break;
		}
		else if (pid < 0)
		{
			perror("Unable to fork");
			break;
		}
		else
		{
			if (waitpid(pid, NULL, 0) < 0)
			{
				perror("Failed to connect to child");
				break;
			}
		}
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

/**
  *tokenise - split string into tokens
  *@str: string to be split.
  *@delims: delimiters.
  *
  *Return: array of tokens
  */
char *tokenise(char *str, char *delims)
{
	char *token, **tokens;
	int pos;
	
	printf("%s\n", str);
	tokens = malloc(sizeof(str) + 2);
	if (tokens == NULL)
	{
		free(tokens);
		free(str);
		return(NULL);
	}
	for (pos = 0; pos < _strlen(str) && token != NULL; pos++, str = NULL)
	{
		token = strtok(str, delims);
		tokens[pos] = token; /* build an array of arguments*/
	}
	tokens[pos] = NULL;

	return (token);

}
