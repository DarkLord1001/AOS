#include<stdio.h> 
#include<dirent.h> 
#include<unistd.h>
void main(int argc , char *argv[])
{
int cnt = 0; 
DIR *dp;
struct dirent *entry; 
dp = opendir(argv[1]);
 
if (dp  == NULL) 
{
printf("Directory does not exists.\n");
_exit(0);
}
while (entry = readdir(dp))
if (entry->d_type == DT_REG) 
cnt++;
printf("Number of files: %d\n", cnt); 
closedir(dp);
}
//./a.out dire_path