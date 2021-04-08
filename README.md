# The Simple Shell

## Synopsis
A simple implementation of a UNIX command line interpreter.

### Description
The simple shell reads input from the standard input, tokenises the command line, interprets the and execute if the line is a valid command

### Usage
All files will be compiled on Ubuntu 14.04 machine with 
`gcc -Wall -Werror -Wextra -pedantic *.c -o shell`
Once the compilation is sucessful, you can execute the program with `./shell`
To exit the program, run you can either:
* `CTRL D`
* `CTRL C`
* `Run $ Exit`
### Supported Commands
* ls
