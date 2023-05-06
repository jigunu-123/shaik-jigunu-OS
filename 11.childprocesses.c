#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i, n = 20, pid;
    for (i = 1; i <= 4; i++) {
        pid = fork();
        if (pid == -1) {
            printf("Error creating child process\n");
            exit(1);
        } else if (pid == 0) {
            switch (i) {
                case 1:
                    printf("Odd numbers: ");
                    for (int j = 1; j <= n; j++) {
                        if (j % 2 != 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                case 2:
                    printf("Even numbers: ");
                    for (int j = 1; j <= n; j++) {
                        if (j % 2 == 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                case 3:
                    printf("Multiples of 3: ");
                    for (int j = 1; j <= n; j++) {
                        if (j % 3 == 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                case 4:
                    printf("Multiples of 5: ");
                    for (int j = 1; j <= n; j++) {
                        if (j % 5 == 0) {
                            printf("%d ", j);
                        }
                    }
                    break;
                default:
                    break;
            }
            printf("\nProcess %d with ID %d completed.\n", i, getpid());
            exit(0);
        }
    }
    return 0;
}
