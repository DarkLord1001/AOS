#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Received SIGINT signal\n");
}

void sigalrm_handler(int signum) {
    printf("Received SIGALRM signal\n");
}

void sigtstp_handler(int signum) {
    printf("Ignoring SIGTSTP signal\n");
}

int main() {
    // Register signal handlers
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
    if (signal(SIGALRM, sigalrm_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }
    if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    // Send SIGALRM signal after 5 seconds
    alarm(5);

    // Loop indefinitely
    while (1) {
        // Wait for signals
        pause();
    }

    return 0;
}
//The program will loop indefinitely and wait for signals. You can send 
//signals to the program using kill command or by pressing Ctrl+C, Ctrl+Z or setting
// an alarm using the alarm() function.

//Replace <signal> with the name of the signal you want to send (e.g. INT, ALRM, TSTP), and <pid> with the 
//process ID of the signals process. You can find the process ID using the ps command.

//For example, to send the SIGINT signal to the signals process, you can run the following command in a new 
//terminal window:

//example:: kill -INT <pid>
