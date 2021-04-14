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


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_number(int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}
