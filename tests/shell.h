#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/* function prototypes */
void def_prompt(void);

/* wrapper function for fork */
pid_t Fork(void)
{
	pid_t pid = fork();

	if (pid < 0)
		perror("Fork error");

	return(pid);
}

/*helper functions */

int _strlen(char *str)
{
	int len = 0;

	while (*(str + len) != '\0')
		len++;

	return (len);
}
#endif /*SHELL_H*/
