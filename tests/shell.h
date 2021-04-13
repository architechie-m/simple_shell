#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include<sys/wait.h>
#include<stdarg.h>
#include <signal.h>

extern char **environ;

/* function prototypes */
void def_prompt(void);

char **tokenise(int ntokens, char *cmdline, char *delims);
int ntokens(char *cmdline, char *delims);

/* wrapper function for fork */
pid_t Fork(void);
int _strlen(char *str);
char *read_line(void);
void free_sptr(int , ...);
void free_dptr(char **str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *src);
void execute(char **tokens, char **argv);
char *getpath(void);
int build_exec(char **cmd,  char **argv);
int builtin(char **);
void inthandler(int);
#endif /*SHELL_H*/
