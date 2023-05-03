#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;

    if (argc != 2) {
        printf("Usage: %s directory_name\n", argv[0]);
        exit(1);
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {  // only print regular files
            printf("%s\n", ent->d_name);
        }
    }

    closedir(dir);
    return 0;
}
//./a.out /media/sf_D_DRIVE/AOS_Prac