#include "shell.h"

/**
 * main - entry point, program starts here
 * @ntokens: Number of tokens in an array
 * @str: string to be tokenised
 * @delims: delimiters
 * Return: NULL terminated array of pointer to strings
 * else, NULL
 */

char **tokenise(int ntokens, char *cmdline, char *delims)
{
	int pos;
	char *str = strdup(cmdline);
	char *token;
	char **tokens;

	tokens = malloc(sizeof(char) * (ntokens + 1));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}

	token = strtok(str, delims);

	for (pos = 0; pos < _strlen(str) && token != NULL; pos++)
	{
		tokens[pos] = strdup(token); /* build an array of arguments*/

		token = strtok(NULL, " \n"); /* terminate it*/


	}
	tokens[pos] = NULL;
	free(str);
	return(tokens);

}

int ntokens(char *cmdline, char *delims)
{
	int count;
	char *str = strdup(cmdline);
	char *token;
	if (str == NULL)
		return (-1);
	token = strtok(str, delims);
	for (count = 0; token != NULL; count++)
	{
		token = strtok(NULL, delims);
	}
	free(str);
	free(token);
	return(count);
}