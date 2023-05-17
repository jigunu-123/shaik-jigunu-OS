#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 20

void *print_even(void *arg)
{
    printf("Even numbers: ");
    for (int i = 0; i <= MAX_NUMBER; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *print_odd(void *arg)
{
    printf("Odd numbers: ");
    for (int i = 1; i <= MAX_NUMBER; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t even_thread, odd_thread;

    // Create the even thread
    if (pthread_create(&even_thread, NULL, print_even, NULL) != 0) {
        printf("Failed to create even thread.\n");
        return 1;
    }

    // Create the odd thread
    if (pthread_create(&odd_thread, NULL, print_odd, NULL) != 0) {
        printf("Failed to create odd thread.\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    return 0;
}
