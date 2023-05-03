#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        exit(1);
    }

    printf("File type: ");

    if (S_ISREG(fileStat.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }

    printf("Group permissions: %o\n", fileStat.st_mode & S_IRWXG);

    return 0;
}
//The program will output the type of file (e.g. "Regular file" or "Directory")
//and the group permissions of the file (e.g. "Group permissions: 755"). If you want to
//check a different file, replace "myfile.txt" with the name of the file you want to check.