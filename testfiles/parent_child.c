#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int k;

	for (k = 0; k < 5; k++)
	{
		if (fork() == 0)
		{

			printf("child %d parent %d\n", getpid(), getppid()), exit(0);

		}
		sleep(1);
		wait(NULL);

	}


	return (0);

}
