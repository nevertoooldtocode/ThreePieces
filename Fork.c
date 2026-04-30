#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define FALSE 0

int callwait() {
    int rc_wait, wstatus;
    rc_wait = wait(&wstatus);
    printf("Wait called by pid %d, rc_wait = %d, wstatus = %d\n", getpid(), rc_wait, wstatus);
    printf("   WIFEXITED(wstatus) = %d\n", WIFEXITED(wstatus));
    if (WIFEXITED(wstatus) != FALSE) {
	printf("   WEXITSTATUS(wstatus) = %d\n", WEXITSTATUS(wstatus));
    }
    printf("   WIFSIGNALED(wstatus) = %d\n", WIFSIGNALED(wstatus));
    if (WIFSIGNALED(wstatus) != FALSE) {
	printf("   WTERMSIG(wstatus) = %d\n", WTERMSIG(wstatus));
    }
    return rc_wait;
}

int main() {
    int rc_fork, x;
    x = 10;
    printf("Starting Fork with pid: %d, x = %d\n", getpid(), x);
    rc_fork = fork();
    if (rc_fork < 0) {
	fprintf(stderr, "Fork failed\n");
	exit(1);
    }
    else if (rc_fork == 0) {
	    x = 20;
	printf("I am the Child with pid: %d, x = %d\n", getpid(), x);
	while (!FALSE);
    }
    else {
	x = 15;
	printf("I am the Parent with pid: %d, my Child has pid: %d, x = %d\n", getpid(), rc_fork, x);
    }
    callwait();
    printf("Ending Fork with pid: %d, x = %d\n", getpid(), x);
    return 0;
}
