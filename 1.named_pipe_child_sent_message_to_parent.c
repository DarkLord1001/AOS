#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPE_NAME "/tmp/myfifo"

int main() {
    int fd;
    pid_t pid;
    char message[] = "Hello, parent! This is the child speaking.";

    // Create the named pipe
    if (mkfifo(PIPE_NAME, 0666) < 0) {
        perror("mkfifo");
        exit(1);
    }

    // Fork the process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process: send a message to the parent
        fd = open(PIPE_NAME, O_WRONLY);

        if (fd < 0) {
            perror("open");
            exit(1);
        }

        write(fd, message, sizeof(message));
        close(fd);

        exit(0);
    } else {
        // Parent process: read the message from the child
        fd = open(PIPE_NAME, O_RDONLY);

        if (fd < 0) {
            perror("open");
            exit(1);
        }

        char buffer[256];
        read(fd, buffer, sizeof(buffer));
        printf("Received message from child: %s\n", buffer);

        close(fd);
        unlink(PIPE_NAME);

        exit(0);
    }
}
//The program will create a named pipe at /tmp/myfifo, fork a child process, and send a message from the child
 //process to the parent process using the named pipe. The parent process will read the message from the named pipe
 // and print it to the console. Finally, the program will delete the named pipe.