#include "print_md_array.h"

#include <stdio.h>

void print_md_array(int rows, int cols, int a[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

void print_md_array_alt(int rows, int cols, int a[][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}
