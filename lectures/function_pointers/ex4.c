#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (int (*)(const void *, const void *))

int cmp(const void *elem1, const void *elem2) {
  char *op1 = *((char **) elem1);
  char *op2 = *((char **) elem2);
  printf("Comparing %s and %s\n", op1, op2);
  return strcmp(op1, op2);
}

int cmp_int(const void *elem1, const void *elem2) {
  int op1 = *((int *) elem1);
  int op2 = *((int *) elem2);
  if (op1 < op2) {
    return -1;
  } else if (op1 == op2) {
    return 0;   
  } else {
    return 1;
  }
}

int main() {
  char *test_names[] = {"red",
			"blue",
			"green",
			"erd",
			"der",
  };
  int num_names = sizeof(test_names)/sizeof(char *);
  
  qsort(test_names,   // array to  sort
	num_names,    // number of elements in array
	sizeof(*test_names),  // size of the elements
	cmp);  // comparison function

  for (unsigned int i = 0; i < num_names; i++) {
    printf("%d: %s\n", i, test_names[i]);
  }
}
