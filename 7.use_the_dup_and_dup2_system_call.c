#include<stdio.h> 
#include<fcntl.h>
 
#include<unistd.h> 
#include<string.h> 
void main() {
char text1[] = "M.Sc. Computer Science\n"; 
char text2[] = "Semesterâ€“II Class\n";
char text3[] = "Advanced Operating Systems\n"; 
char text4[] = "Practical Examination\n";
int fd1 = open("./temp.txt", O_WRONLY | O_APPEND); 
int fd2 = dup(fd1);
int fd3 = dup2(fd2, 0); 
int fd4 = dup2(fd3, 1);

write(fd1, text1, strlen(text1)); 
write(fd2, text2, strlen(text2)); 
write(fd3, text3, strlen(text3)); 
printf("%s", text4);
}
// create first temp.txt write some content in it
// ./a.out
//open file: cat temp.txt