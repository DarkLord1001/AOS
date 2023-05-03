#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void sigint_handler(int sig) {
 sleep(5);
 printf("\nSignal is unblock\n");
 _exit(0);
}
int main() {
 signal(SIGINT, sigint_handler);
 printf("\nSignal is Blocked for 5 seconds\n");
 while (1) {
 // Wait for signals
 }
 return 0;
}
//./a.out
//press ctrl+c five seconds its automatically unblock