#include "shell.h"

int main(int argc,  char **argv)
{
	char *line = NULL;
	size_t len = 0;
	char *token; /* the token to be split */
	pid_t pid;
	char **tokens;/* create an array of tokens from the split tokens, and allocate some memory*/
	int status;
	int pos = 0;


	while (1)
	{
		def_prompt();

		if (getline(&line, &len, stdin) == -1)
			break;

		token  = strtok(line, " ,\n\t\r;");
		tokens = malloc(sizeof(line) + 2);
		for (pos = 0; pos < _strlen(line) && token != NULL; pos++)
		{
			tokens[pos] = token; /* build an array of arguments*/

			token = strtok(NULL, " \n"); /* terminate it*/


		}
		tokens[pos] = NULL;
		pid = Fork();
		if (pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				free(tokens);
				free(line);
				free(token);
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
			exit(0);
		}

		else
			wait(NULL);

		//              if(feof(stdin))
                //{
		//      exit(0);
                //}
	}
	free(tokens);
	free(token);
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
