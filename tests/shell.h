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
<<<<<<< HEAD
char **tokenise(int ,char *, char *);
=======
char **tokenise(int ntokens, char *cmdline, char *delims);
int ntokens(char *cmdline, char *delims);
>>>>>>> 1e8b66fa6d040c3146085f7eb18a9d48b5fed95c


/* wrapper function for fork */
pid_t Fork(void);
int _strlen(char *str);
#endif /*SHELL_H*/
