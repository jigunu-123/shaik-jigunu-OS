#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
    int fd, numBytes;
    char buffer[BUFFER_SIZE];

    // Create a file using system call
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error creating the file");
        exit(1);
    }

    printf("Enter data to write to the file (max %d characters):\n", BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);

    // Write user input to the file
    numBytes = write(fd, buffer, sizeof(buffer));
    if (numBytes == -1) {
        perror("Error writing to the file");
        exit(1);
    }

    close(fd);

    // Reopen the file for reading
    fd = open("data.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file for reading");
        exit(1);
    }

    // Read data from the file and print it on the console
    printf("\nContents of the file:\n");
    while ((numBytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, numBytes);
    }

    close(fd);

    return 0;
}

