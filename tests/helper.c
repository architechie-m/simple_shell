#include "shell.h"

/* wrapper function for fork */
pid_t Fork(void)
{
        pid_t pid = fork();

        if (pid < 0)
                perror("Fork error");

        return(pid);
}

/*helper functions */

int _strlen(char *str)
{
        int len = 0;

        while (*(str + len) != '\0')
                len++;

        return (len);
}
