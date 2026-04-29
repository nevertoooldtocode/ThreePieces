#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid, x;
    x = 10;
    printf("Start for Fork with pid: %d, x = %d\n", getpid(), x);
    pid = fork();
    if (pid < 0) {
	fprintf(stderr, "Fork failed\n");
	exit(1);
    }
    else if (pid == 0) {
	    x = 20;
	printf("I am the Child with pid: %d, x = %d\n", getpid(), x);
    }
    else {
	//wait(NULL);
	x = 15;
	printf("I am the Parent with pid: %d, my Child has pid: %d, x = %d\n", getpid(), pid, x);
    }
    wait(NULL);
    printf("Ending Fork with pid: %d, x = %d\n", getpid(), x);
    return 0;
}
