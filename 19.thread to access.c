#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_COUNT 2

int shared_data = 10;
sem_t semaphore;

void *thread_func1(void *arg)
{
    int data;

    sem_wait(&semaphore);
    data = shared_data;
    shared_data *= 2;
    sem_post(&semaphore);

    printf("Thread 1: Original data = %d, Doubled data = %d\n", data, shared_data);

    pthread_exit(NULL);
}

void *thread_func2(void *arg)
{
    int data;

    sem_wait(&semaphore);
    data = shared_data;
    shared_data *= 5;
    sem_post(&semaphore);

    printf("Thread 2: Original data = %d, Five times data = %d\n", data, shared_data);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_COUNT];

    sem_init(&semaphore, 0, 1);

    pthread_create(&threads[0], NULL, thread_func1, NULL);
    pthread_create(&threads[1], NULL, thread_func2, NULL);

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}
