#include <stdio.h>
#include <assert.h>

// The callback function type
typedef void (*callback_t)(int);

// A function that accepts a callback
void process_numbers(int *array, int size, callback_t callback) {
  assert (callback != NULL);
  
  for (int i = 0; i < size; i++) {
    callback(array[i]);
  }
}

// Two possible callbacks
void print_number(int num) {
  printf("%d ", num);
}

void print_square(int num) {
  printf("%d ", num * num);
}

int main() {
  int numbers[] = {1, 2, 3, 4, 5};

  printf("Numbers: ");
  process_numbers(numbers, 5, print_number);

  printf("\nSquares: ");
  process_numbers(numbers, 5, print_square);
}
