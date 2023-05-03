#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>
int main(argc,argv)
int argc;
char *argv[];
{
 int fd,skval;
 char c;
 if(argc !=2)
 _exit(0);
 fd = open(argv[1],O_WRONLY|O_CREAT);
 if(fd == -1)
 _exit(0);
 for(int j=0; j<3; j++)
 {
 skval = lseek(fd,100L,1);
 for(int i=0; i<5;i++)
 write(fd,"Hello world !",strlen("Hello world !"));
 }
 close(fd);
 return 0;
}
