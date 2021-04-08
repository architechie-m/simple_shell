#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (!feof(stdin))
	{
		printf("$  ");
		while ((read = getline(&line, &len, stdin)) != -1) {

			printf("%s", line);
			break;
		}
	}

	free(line);
	exit(EXIT_SUCCESS);
}
