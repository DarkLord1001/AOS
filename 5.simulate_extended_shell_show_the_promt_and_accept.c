#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
 char line[80];
 char* args[5];
 int status;
 while (1) {
 printf("extended-shell> ");
 if (fgets(line,80, stdin) == NULL)
 break;
 char* token = strtok(line, " \t\n");
 int i = 0;
 while (token != NULL && i < 5) {
 args[i] = token;
 token = strtok(NULL, " \t\n");
 i++;
 }
 args[i] = NULL;
 int pid = fork();
 if (pid == -1) {
 perror("fork");
 exit(1);
 } else if (pid == 0) {
 if (execvp(args[0], args) == -1) {
 perror("execvp");
 exit(1);
 }
 } else
 wait(&status);

 if (strcmp(args[0], "exit") == 0)
 break;
 }
 return 0;
}