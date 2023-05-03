#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat file_stats;

    // Check if file name is provided
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Get file stats
    if (stat(argv[1], &file_stats) != 0) {
        printf("Error: Failed to get file stats\n");
        return 1;
    }

    // Print file type
    if (S_ISREG(file_stats.st_mode)) {
        printf("%s: Regular file\n", argv[1]);
    } else if (S_ISDIR(file_stats.st_mode)) {
        printf("%s: Directory\n", argv[1]);
    } else if (S_ISCHR(file_stats.st_mode)) {
        printf("%s: Character device\n", argv[1]);
    } else if (S_ISBLK(file_stats.st_mode)) {
        printf("%s: Block device\n", argv[1]);
    } else if (S_ISFIFO(file_stats.st_mode)) {
        printf("%s: FIFO (named pipe)\n", argv[1]);
    } else if (S_ISSOCK(file_stats.st_mode)) {
        printf("%s: Socket\n", argv[1]);
    } else if (S_ISLNK(file_stats.st_mode)) {
        printf("%s: Symbolic link\n", argv[1]);
    } else {
        printf("%s: Unknown file type\n", argv[1]);
    }

    return 0;
}
//./a.out filename