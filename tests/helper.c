#include "shell.h"
/**
  *Fork -  wrapper function for fork.
  *Return: process created.
  */
pid_t Fork(void)
{
	pid_t pid = fork();

	if (pid < 0)
		perror("Fork error");
	return (pid);
}

/**
  *builtin - exits from the shell.
  *@tokens: array of strings based on user inout.
  *Return: 0 if exit is found, 1 otherwise.
  */
int builtin(char **tokens)
{
	if (!_strcmp(tokens[0], "exit"))
	{
		return (0);
	}
	return (1);
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
	write(STDOUT_FILENO, "> ", 2);
}

