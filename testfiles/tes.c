#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int i;

	for (i = 0; i < 6; i++)
		if (fork() == 0)
		{
			printf("son: %d parent: %d\n", getpid(), getppid()), exit(0);
		}
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);



}
