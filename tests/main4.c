#include "shell.h"

int main(int __attribute__((unused))argc,  char **argv)
{
	int i;
	int count;
	pid_t pid;
	char **tokens;/* create an array of tokens from the split tokens, and allocate some memory*/
	char *delims = " ,\n\t\r;";
	int flag = 0, flag2 = 0;
	char cmd[1024];
	char *line = NULL;
	char *environ[] = {(char *)"PATH=/bin", NULL}; /* environmen path */

	while (1)
	{
		def_prompt();

		line = read_line();
		if (line == NULL)
			break;

		count = ntokens(line, delims);

		tokens = tokenise(count, line, delims);

		if (tokens == NULL)
		{
			free(line);
			break;
		}
		if (_strcmp(line, "exit\n") == 0)
			break;


		pid = Fork();
		if (pid == 0)
		{

			_strcpy(cmd, "/bin/");
			for (i = 0; tokens[0] != '\0'; i++)
			{
				if (tokens[0][i] == cmd[i])
				{
					flag2 = 1;
				}
				else
				{
					_strcat(cmd, tokens[0]);
					flag = 1;
					break;

				}
			}
			if (flag2)
			{
				if (execve(tokens[0], tokens, environ) == -1)
				{
					free_dptr(tokens);
					free(line);
					perror(argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			if (flag)
			{

				if (execve(cmd, &tokens[0], environ) == -1)
				{
					free_dptr(tokens);
					free(line);
					perror(argv[0]);
					exit(EXIT_FAILURE);
				}
			}
		}

		else
			wait(NULL);
		free(line);
		free_dptr(tokens);


	}
	free_dptr(tokens);
	free_sptr(1, line);
	exit(EXIT_SUCCESS);
}
