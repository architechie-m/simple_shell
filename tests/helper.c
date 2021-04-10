#include "shell.h"

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


/**
 * def_prompt - write $ on a new line.
 *
 * Return: void.
 */
void def_prompt(void)
{
        write(1, "$ ", 2);
}

/**
 * def_prompt2 - Write > on a new line
 *
 * Return: void
 */

void def_prompt2(void)
{
	write (STDOUT_FILENO, "> ", 2);
}

/**
 * free_sptr - free n numbers of pointers to a string
 * @n: pointers to free
 */

void free_sptr(int n, ...)
{
	int i;
	char *str;
	va_list list;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(list, char *);
		free(str);
	}
	va_end(list);
}

void free_dptr(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}
