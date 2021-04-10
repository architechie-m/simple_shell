#include "shell.h"

int main(int __attribute__((unused))argc,  char **argv)
{
	char *line = NULL;
	pid_t pid;
	char *parameters[20];
	char cmd[20];
	char *environ[] = { (char *) "PATH=/bin/", 0};
	while (1)
	{
		def_prompt();

		read_line(line, parameters);
		printf("%s", line);

		pid = Fork();
		if (pid != 0)
		{
			wait(NULL);
		}
		else
		{
			strcpy (cmd, "/bin/");
			strcat(cmd, line);

			if (execve(cmd, parameters, environ) == -1)
			{
				free(line);
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}

		if (strcmp(line, "exit\n") == 0)
			break;


	}

	free(line);
	exit(EXIT_SUCCESS);
}
