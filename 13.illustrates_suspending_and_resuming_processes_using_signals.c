#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main() {
 int pid = fork();
 if (pid == 0)
 {
 printf("Child process %d is running...\n", getpid());
 while (1)
 {
 printf("Child process %d is running...\n", getpid());
 sleep(1);
 }
 }
 else
 {
 printf("Parent process %d is running...\n", getpid());
 sleep(2);
 printf("Sending SIGSTOP signal to child process %d...\n", pid);
 kill(pid, SIGSTOP);
 printf("Child process %d has been suspended.\n", pid);
 sleep(2);
 printf("Sending SIGCONT signal to child process %d...\n", pid);
 kill(pid, SIGCONT);
 printf("Child process %d has been resumed.\n", pid);
 sleep(2);
 printf("Sending SIGTERM signal to child process %d...\n", pid);
 kill(pid, SIGTERM);
 printf("Child process %d has been terminated.\n", pid);
 }
 return 0;
}
