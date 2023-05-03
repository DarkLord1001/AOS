#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void sigchld_handler(int sig) {
 printf("Child process terminated.\n");
}
int main() {
 pid_t pid;
 int status;
 signal(SIGCHLD, sigchld_handler);
 pid = fork();
 if (pid == 0) {
 printf("Child process starting...\n");
 sleep(10);
 printf("Child process exiting...\n");
 exit(0);
 }
 else if (pid > 0)
 {
 printf("Parent process waiting for child...\n");
 alarm(5);
 wait(&status);
 }
 else
 {
 printf("Fork failed.\n");
 exit(0);
 }
 printf("Parent process exiting.\n");
 return 0;
}