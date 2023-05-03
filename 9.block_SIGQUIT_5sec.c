#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sigint_handler(int sig) {
}
void handle_sigtstp(int sig) {
 sleep(5);
 printf("\nSignal is unblock\n");
 _exit(0);
}
int main() {
 signal(SIGINT, sigint_handler);
 signal(SIGTSTP, handle_sigtstp);
 while (1) {
 // Loop indefinitely
 }
 return 0;
}