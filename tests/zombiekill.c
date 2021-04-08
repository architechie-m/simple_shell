#include "holberton.h"

int main() {
    pid_t child;
    int i;

    printf("-----------------------------------\n");
    about("Parent");

    for (i = 0; i < 3; i++) {
        printf("Now ..  Forking !!\n");
        child = fork();

        if (child < 0) {
            perror ("Unable to fork");
            break;
        } else if (child == 0) {
            printf ("In child #%d\n", (i+1));
            about ("Child");
            break;
        } else {
            /* in parent */
            if (waitpid(child, NULL, 0) < 0) {
                perror("Failed to collect child process");
                break;
            }
        }
    }

    return 0;
}

void about(char *msg)
{

 pid_t me;
 pid_t oldone;

 me = getpid();
 oldone = getppid();

 printf("***[%s] PID = %d   PPID = %d.\n", msg, me, oldone);

}
