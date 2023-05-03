#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h>

void typeline(char *op, char *fn)
{

int fh,i,j,n;
 
char c;
fh = open(fn,O_RDONLY); 
if(fh == -1)
{

printf("File %s not found.\n", fn); 
return;
}

if(strcmp(op, "a") == 0)
{

while(read(fh, &c, 1) > 0) 
printf("%c", c);
close(fh); 
return;
}

n = atoi(op); 
if(n > 0)
{

i = 0;
while(read(fh, &c, 1) > 0)
{

printf("%c", c); if(c == '\n')
i++;
if(i == n) 
break;
}
}

if(n < 0)
{

i = 0;
while(read(fh, &c, 1) > 0)
{
 
if(c == '\n') 
i++;
}
lseek(fh, 0, SEEK_SET);
j = 0;
while(read(fh, &c, 1) > 0)
{

if(c == '\n') 
j++;
if(j == i+n) 
break;
}

while(read(fh, &c, 1) > 0) 
printf("%c", c);
}

close(fh);
}


int main()
{

char command[60],t1[20],t2[20],t3[20]; 
int n;
while(1)
{

printf("myshell$ "); 
fflush(stdin);
fgets(command,60,stdin);
n = sscanf(command,"%s %s %s",t1,t2,t3);


switch(n)
{
case 1:
 
char a=t1[0]; 
if(a=='q')
return 0; 
if(!fork())
{
execlp(t1,t1,NULL); 
perror(t1);
}
break; 
case 2:
if(!fork())
{
execlp(t1,t1,t2,NULL); 
perror(t1);
}
break; 
case 3:
if(strcmp(t1,"typeline")==0) typeline(t2,t3);
else
{
if(!fork())
{
execlp(t1,t1,t2,t3,NULL); 
perror(t1);
}

}
break;
}
}
}
//./a.out
//run this
//myshell$ typeline +5 demo.txt