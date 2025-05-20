#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *args[] = {"./hello", NULL};

volatile unsigned int counter = 0;

int main(int argc, char *argv[], char *envp[])
{
    int ret, status;
    pid_t pid, cpid;

    pid = fork();
    if (pid < 0) {
       fprintf(stderr, "fork failed\n");
       return 1;
    }
    if (pid != 0) {  /* parent */
        for (int i = 0; i < 5; i++) {
            counter += 1;
        }
        cpid = waitpid(pid, &status, 0);
        if (cpid != pid) {
            fprintf(stderr, "waitpid failed\n");
            return 1;
        }
        printf("Parent counter = %d\n", counter);
    }
    else {  /* child */
        for (int i = 0; i < 5; i++) {
            counter += 1;
        }
        printf("Child counter = %d\n", counter);
    } 
 
    return 0;
}
