#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
int count = 0;
void sig_handler(int sig) {
 printf("SIGQUIT signal occurred\n");
 count++;
 if (count == 5)
 {
 printf("Exiting...\n");
 _exit(0);
 }
}
int main() {
 signal(SIGQUIT, sig_handler);
 while (1) {
 // Wait for signals
 }
 return 0;
}
//./a.out
//press ctrl+\ five times