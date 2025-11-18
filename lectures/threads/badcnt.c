#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

const unsigned int N = 100000000;

/* shared variable */
unsigned int cnt = 0;

void *count(void *arg) {
  int *cnt = (int *)arg;

  for (unsigned int i = 0; i < N; i++) {
    (*cnt)++;
  }

  return NULL;
}


int main(void) {
    pthread_t tid1, tid2;

    int cnt = 0;

    pthread_create(&tid1, NULL, count, &cnt);
    pthread_create(&tid2, NULL, count, &cnt);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    if (cnt == N * 2) {
        printf("OK cnt=%u\n", cnt);
    } else {
        printf("BOOM cnt=%u\n", cnt);
    }

    return 0;
}



