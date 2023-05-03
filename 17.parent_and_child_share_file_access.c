#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
int main() {
 int fd;
 pid_t pid;
 char buf[256];
 fd = open("shared_file.txt", O_RDWR | O_CREAT,0644);
 pid = fork();
 if (pid < 0) {
 perror("fork");
 exit(0);
 }
 else if (pid == 0)
 {
 sprintf(buf, "Child process writing to file\n");
 write(fd, buf, strlen(buf));
 exit(0);
 }
 else
 {
 sprintf(buf, "Parent process writing to file\n");
 write(fd, buf, strlen(buf));
 exit(0);
 }
 return 0;
}
//gcc prog_name.c
//./a.out
//check shared_file.txt in directory