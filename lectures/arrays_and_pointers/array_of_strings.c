#include <stdio.h>
#include <stdlib.h>

char *bang() {
  char *s = (char*)malloc(sizeof(char) * 2);
  s[0] = '!';
  s[1] = '\0';
  return s;
}

int main() {
  int n = 3;

  char **ptr_sample = (char**)malloc(sizeof(char*) * n);

  ptr_sample[0] = "hello";
  ptr_sample[1] = "world";
  ptr_sample[2] = bang();

  for (int i = 0; i < n; i++) {
    printf("sample[%d] = %s\n", i, ptr_sample[i]);
  }

  free(ptr_sample[2]);
  free(ptr_sample);
}
