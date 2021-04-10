#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>
/* function prototypes */
void def_prompt(void);

char **tokenise(int ntokens, char *cmdline, char *delims);
int ntokens(char *cmdline, char *delims);

/* wrapper function for fork */
pid_t Fork(void);
int _strlen(char *str);
#endif /*SHELL_H*/
