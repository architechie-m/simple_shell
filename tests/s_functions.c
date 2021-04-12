#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string- to be compared with the second one
 * @s2: second string- to be compare to the first one
 *
 * Return: eturn an integer less than, equal to, or greater than zero if s1
 * (or the first n bytes thereof) is found, respectively, to be less than
 * to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int count, output;

	count = 0;
	while (*(s1 + count) == *(s2 + count) && *(s1 + count) != '\0')
		count++;

	output = (*(s1 + count) - *(s2 + count));

	return (output);
}

/**
 *_strcat - function that concatenates two strings.
 *@dest: pointer to destination string.
 *@src: pointer to source string.
 *
 *Return: pointer to destination string.
 */
char *_strcat(char *dest, char *src)
{
	int length, j; /* j will hold the length of the source */
	length = 0;
	while (dest[length] != '\0')
	{
		length++;
	}
	for (j = 0; src[j] != '\0'; j++, length++)
	{
		dest[length] = src[j];
	}
	dest[length] = '\0';
	return (dest);
}


/**
 * _strcpy - copies string from src to dest
 * @dest: where string will go
 * @src: where string is from
 *
 * Return: returns string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
  *_strdup - duplicate string in memory.
  *@src: string.
  *
  *Return: pointer to string.
  */
char *_strdup(char *src)
{
	char *str;
	char *p;
	int len = 0;
	
	len = _strlen(src);
	str = malloc(len + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}

int builtin(char **tokens)
{
	if (!_strcmp(tokens[0], "exit"))
	{
		return (0);
	}
	return (1);
}
