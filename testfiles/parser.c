#include <stdio.h>
#include <stdlib.h>

int parseline(char *buf, char **argv)
{
	char *delimiter;
	int argc;
	int bck;
	int len;
	

	while (*(buf + len ) != '\0')
	{
		len++;
	}

	buf[len - 1] = ' ';/* replace the trailing '\n' with space*/
	while (*buff && (*buf == ' '))
		buf++;

	argc = 0;
	while ((delim = 
