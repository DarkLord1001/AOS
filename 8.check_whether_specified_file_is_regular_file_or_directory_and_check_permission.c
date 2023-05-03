#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat st;

    // Check if the user has provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Use stat() to get information about the file
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(1);
    }

    // Check if the file is a directory
    if (S_ISDIR(st.st_mode)) {
        printf("%s is a directory.\n", argv[1]);
    }
    // Check if the file is a regular file
    else if (S_ISREG(st.st_mode)) {
        printf("%s is a regular file.\n", argv[1]);
    }
    else {
        printf("%s is not a regular file or directory.\n", argv[1]);
        exit(1);
    }

    // Print the user permissions of the file
    printf("User permissions: ");
    printf((st.st_mode & S_IRUSR) ? "r" : "-");
    printf((st.st_mode & S_IWUSR) ? "w" : "-");
    printf((st.st_mode & S_IXUSR) ? "x" : "-");
    printf("\n");

    return 0;
}
//gcc filename_permissions.c -o filename

