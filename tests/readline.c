#include "shell.h"
/**
  *read_line - reads input from the user.
  *Return: string read.
  */
char *read_line(void)
{
	size_t len = 0;
	char *line = NULL;
	int length;
	/* read the cmdline */

	if (getline(&line, &len, stdin) != -1)
	{
		length = _strlen(line);
		if (line[length - 1] == '\n')
		{
			if (line[_strlen(line) - 2] == '\\')
			{
				line[length -2] = '\0';
				length -= 2;
				def_prompt2();
				return (line);
			}
		}
	}
	else
		free(line);
	return (line);
	free(line);
	exit(0);
}
