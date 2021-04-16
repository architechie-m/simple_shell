#include "shell.h"
#include <string.h>

/**
 * tokenise - entry point, program starts here
 * @ntokens: Number of tokens in an array
 * @cmdline: string to be tokenised
 * @delims: delimiters
 * Return: NULL terminated array of pointer to strings
 * else, NULL
 */

char **tokenise(int ntokens, char *cmdline, char *delims)
{
	int pos;
	char *str = _strdup(cmdline);
	char *token;
	char **tokens;

	token = strtok(str, delims);

	if (token)
	{
		tokens = malloc(sizeof(char **) * (ntokens + 1));
		if (tokens == NULL)
		{
			free_dptr(tokens);
			return (NULL);
		}

		for (pos = 0; token != NULL; pos++)
		{
			tokens[pos] = _strdup(token); /* build an array of arguments*/
			token = strtok(NULL, delims); /* terminate it*/
		}



		tokens[pos] = NULL;
		free_sptr(2, str, token);
		return (tokens);
	}
	free(str);
	return (NULL);
}

/**
  *ntokens - counts number of tokens in cmdline.
  *@cmdline: user input.
  *@delims: characters present in input used to break input into tokens.
  *
  *Return: number of tokens.
  */
int ntokens(char *cmdline, char *delims)
{
	int count;
	char *str = _strdup(cmdline);
	char *token;

	if (str == NULL)
	{
		return (-1);
	}
	token = strtok(str, delims);
	if (token == NULL)
	{
		free(str);
		return (-1);
	}

	for (count = 0; token != NULL; count++)
	{
		token = strtok(NULL, delims);
	}

	free_sptr(2, str, token);
	return (count);
}
