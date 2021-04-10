#include "shell.h"

int main(int __attribute__((unused))argc,  char **argv)
{
	int i;
	int count;
	pid_t pid;
	char **tokens;/* create an array of tokens from the split tokens, and allocate some memory*/
	char *delims = " ,\n\t\r;";
	int flag = 0, flag2 = 0;
	size_t len = 0;
	char cmd[1024];
	char *line = NULL;
	char *environ[] = {(char *)"PATH=/bin", NULL}; /* environmen path */
	char strtemp[1024];

	while (1)
	{
		def_prompt();

		if (getline(&line, &len, stdin) == -1)
			break;


		count = ntokens(line, delims);

		tokens = tokenise(count, line, delims);


		if (strcmp(line, "exit\n") == 0)
			break;


		pid = Fork();
		if (pid == 0)
		{

			strcpy(cmd, "/bin/");
			for (i = 0; tokens[0] != '\0'; i++)
			{
				if (tokens[0][i] == cmd[i])
				{
					strtemp[i] =  tokens[0][i];
					flag2 = 1;
				}
				else
				{
					strcat(cmd, tokens[0]);
					flag = 1;
					break;

				}
			}
			strtemp[i] = '\0';
			printf("%s", strtemp);
			if (flag2)
			{
				if (execve(tokens[0], tokens, environ) == -1)
				{
					free(tokens);
					free(line);
					perror(argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			if (flag)
			{

				if (execve(cmd, &tokens[0], environ) == -1)
				{
					free(tokens);
					free(line);
					perror(argv[0]);
					exit(EXIT_FAILURE);
				}
			}
		}

		else
			wait(NULL);



	}
	free(tokens);
	free(line);
	exit(EXIT_SUCCESS);
}
