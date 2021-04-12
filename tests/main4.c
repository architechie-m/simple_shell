#include "shell.h"

extern char **environ;

int main(int __attribute__((unused))argc,  char **argv)
{
	int count;
	pid_t pid;
	char **tokens;/* create an array of tokens from the split tokens, and allocate some memory*/
	char *delims = " ,\n\t\r;";
	char *line = NULL;
	
	(void)argv;

	while (1)
	{
		def_prompt();

		line = read_line();
		if(line == NULL)
			break;
		if (_strcmp(line, "exit\n") == 0)
			break;

		count = ntokens(line, delims);

		tokens = tokenise(count, line, delims);

		pid = Fork();
		if (pid == 0)
			getpath(tokens, argv);
		else
			wait(NULL);
		free(line);
		free_dptr(tokens);

	}
	free_dptr(tokens);
	free(line);
	exit(EXIT_SUCCESS);
}
