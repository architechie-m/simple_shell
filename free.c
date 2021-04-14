#include "shell.h"

/**
 * free_sptr - free n numbers of pointers to a string
 * @n: number of pointers to free.
 * Return: void.
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
/**
 *free_dptr - frees array of strings.
 *@str: array of strings.
 *Return: void.
 */
void free_dptr(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}
