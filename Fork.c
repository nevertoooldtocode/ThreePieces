#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid;
    printf("Start for Fork with pid: %d\n", getpid());
    pid = fork();
    if (pid < 0) {
	fprintf(stderr, "Fork failed\n");
	exit(1);
    }
    else if (pid == 0) {
	printf("I am the Child with pid: %d\n", getpid());
    }
    else {
	wait(NULL);
	printf("I am the Parent with pid: %d, my Child has pid: %d\n", getpid(), pid);
    }
    return 0;
}
