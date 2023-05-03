#include <stdio.h>
#include <dirent.h>

int main() {
    int count = 0;
    struct dirent *entry;
    DIR *dir = opendir("/path/to/directory"); // replace with desired directory path

    if (dir == NULL) {
        printf("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // check if entry is a regular file
            count++;
        }
    }

    printf("Number of files in directory: %d", count);

    closedir(dir);
    return 0;
}

