#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
int count = 0;
void sigint_handler(int sig) 
{
 count++;
 printf("SIGINT signal occurred\n");
 if (count == 6)
 exit(0);
}
int main() {
 signal(SIGINT, sigint_handler);
 while (1) 
 {
 // Wait for signals
 }
 return 0;
}

//./a.out
//press ctrl+c six times