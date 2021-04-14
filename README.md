# The Simple Shell Project

## Synopsis
A simple implementation of a UNIX command line interpreter.

### Description
The simple shell reads input from the standard input, tokenises the command line, interprets the and execute if the line is a valid command

### Usage
All files will be compiled on Ubuntu 14.04 machine with
`gcc -Wall -Werror -Wextra -pedantic *.c -o shell`.

Once the compilation is sucessful, you can execute the program with `./shell`
To exit the program,`Run $ Exit`.

This simple shell supports all shell commands in the PATH environment, including, but not limited to: 
`cat', `ls`, 'w'.

### Supported Builtin Commands
* `cd' - Change directory
* `help'
* `exit`
* `env`

## Functions Used

| Function | Description |
| --- | --- |
| Readline | Reads user command from stdin |
| Tokenise | Splits user input into array of tokens |
| ntokens | Counts the number of tokens for each command line |
| Fork | Wrapper function for fork() to handle errors |
| num | Calculate the number of builtin functions |
| help | Implements the  builtin `help` command |
| exit_1 | Implements `exit` command |
| cd | Implements the builtin command `cd` |
| Compare | Compares user input with the builtin, executes when the input is a builtin |
| def_prompt | Displays a `$` prompt |
| def_prompt2 | Displays a `>` prompt |
| free_sptr | Frees single pointers |
| free_dptr | Frees double pointers |
| getpath | Finds `PATH` in `environ` |
| build_exec| Builds absolute path for a command and executes the cmd |
| inthandler | Implements `CTRL D` |
| _strcmp | Compares two strings |
| _strcat | Concatenates two strings |
| _strdup | Duplicates a string |
| _strlen | Finds the length of a string |
