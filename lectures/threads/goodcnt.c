#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

const unsigned int N = 100000000;

struct worker {
  int *cnt;
  pthread_mutex_t *sem_ptr;
};

void *count(void *args) {
  struct worker *data = args;
  int *cnt = data->cnt;
  pthread_mutex_t *sem_ptr = data->sem_ptr;

  for (unsigned int i = 0; i < N; i++) {
    pthread_mutex_lock(sem_ptr);
    *cnt = *cnt + 1;
    pthread_mutex_unlock(sem_ptr);
  }

  return NULL;
}


int main(void) {
    pthread_t tid1, tid2;
    pthread_mutex_t sem;
    pthread_mutex_init(&sem, NULL);

    int cnt = 0;

    struct worker worker_args = {.cnt = &cnt, .sem_ptr = &sem};

    pthread_create(&tid1, NULL, count, &worker_args);
    pthread_create(&tid2, NULL, count, &worker_args);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    if (cnt == N * 2) {
      printf("OK cnt=%u\n", cnt);
    } else {
      printf("BOOM cnt=%u\n", cnt);
    }

    return 0;
}


