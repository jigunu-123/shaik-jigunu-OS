#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3

struct File {
    char name[20];
};

struct Directory {
    char name[20];
    struct File files[MAX_FILES];
};

struct User {
    char name[20];
    struct Directory directory;
};

struct User users[MAX_USERS];

void createDirectory(struct User* user) {
    printf("Enter directory name for %s: ", user->name);
    scanf("%s", user->directory.name);
}

void createFile(struct User* user) {
    printf("Enter file name for %s: ", user->name);
    scanf("%s", user->directory.files[user->directory.fileCount].name);
    user->directory.fileCount++;
}

int main() {
    for (int i = 0; i < MAX_USERS; i++) {
        printf("Enter name for user %d: ", i+1);
        scanf("%s", users[i].name);
        createDirectory(&users[i]);

        printf("Enter number of files for user %d: ", i+1);
        int numFiles;
        scanf("%d", &numFiles);

        for (int j = 0; j < numFiles; j++) {
            createFile(&users[i]);
        }
    }

    // Displaying the created directories and files
    printf("\nDirectory Structure:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        printf("User: %s\n", users[i].name);
        printf("Directory: %s\n", users[i].directory.name);
        printf("Files: ");
        for (int j = 0; j < users[i].directory.fileCount; j++) {
            printf("%s ", users[i].directory.files[j].name);
        }
        printf("\n\n");
    }

    return 0;
}
