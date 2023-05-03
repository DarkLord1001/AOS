#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;
    char *dir_name;
    int len;

    if (argc < 2) {
        printf("Usage: %s directory_name\n", argv[0]);
        return 1;
    }

    dir_name = argv[1];
    len = strlen(dir_name);

    if (dir_name[len-1] != '/') {
        //dir_name = realloc(dir_name, len+2);
        strcat(dir_name, "/");
    }

    dir = opendir(dir_name);

    if (dir == NULL) {
        printf("Error opening directory %s\n", dir_name);
        return 1;
    }

    printf("Contents of directory %s:\n", dir_name);

    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);

    return 0;
}
// ./a.out dir_path