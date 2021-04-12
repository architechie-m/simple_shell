#include "shell.h"

char *read_line(void)
{

        size_t len = 0;
        char *line = NULL;


/* read the cmdline */

	if (getline(&line, &len, stdin) == -1) /* read the line from stdin */
	{
		if (feof(stdin)) /* check the cause of failure */
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);

}
