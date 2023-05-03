//Write a program to create a Unnamed pipe where parent sends messages to child.
#include<stdio.h> 
#include<string.h>
#include <sys/types.h> 
#include <unistd.h> 
#include<fcntl.h>
int main()
{
int fd[2], pid; 
char buff[50];
char msg[]="Hello"; 
pipe(fd);
if((pid=fork()) != 0)
{
printf("\nIn Parent\n"); 
close(fd[0]);
printf("Parent with PID %d sending message to child\n",getpid()); write(fd[1],msg,strlen(msg));
close(fd[1]);
}
else
{
printf("\nIn Child\n"); 
close(fd[1]);
printf("Child with PID %d recived message from parent\n",getpid()); read(fd[0],buff,sizeof(msg));
printf("%s\n",buff); close(fd[0]);
}
return 0;
}
//output ./a.out
