#include <pthread.h>
#include <stdio.h>

void *thread(void *data);

int main() {
        pthread_t tid;

        pthread_create(&tid, NULL, thread, "hello, world!");
        pthread_join(tid, NULL);

        return 0;
}

void *thread(void *data) {
  char *str =  data;
  printf("%s\n", str);
  
  return NULL;
}
