#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE], count, in, out;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_not_full = PTHREAD_COND_INITIALIZER, buffer_not_empty = PTHREAD_COND_INITIALIZER;

#define PRODUCE(x) \
  buffer[in] = x; \
  printf("Produced %d\n", buffer[in]); \
  in = (in + 1) % BUFFER_SIZE; \
  count++;

#define CONSUME(x) \
  x = buffer[out]; \
  printf("Consumed %d\n", x); \
  out = (out + 1) % BUFFER_SIZE; \
  count--;

void *producer(void *arg) {
  for (int i = 0; i < 4; i++) {
    pthread_mutex_lock(&mutex);
    while (count == BUFFER_SIZE) pthread_cond_wait(&buffer_not_full, &mutex);
    PRODUCE(i);
    pthread_cond_signal(&buffer_not_empty);
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

void *consumer(void *arg) {
  for (int i = 0; i < 1; i++) {
    pthread_mutex_lock(&mutex);
    while (count == 0) pthread_cond_wait(&buffer_not_empty, &mutex);
    int item;
    CONSUME(item);
    pthread_cond_signal(&buffer_not_full);
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t prod_thread, cons_thread;
  pthread_create(&prod_thread, NULL, producer, NULL);
  pthread_create(&cons_thread, NULL, consumer, NULL);
  pthread_join(prod_thread, NULL);
  pthread_join(cons_thread, NULL);
  printf("Buffer is %s\n", count == 0 ? "EMPTY" : count == BUFFER_SIZE ? "FULL" : "neither FULL nor EMPTY");
  return 0;
}

