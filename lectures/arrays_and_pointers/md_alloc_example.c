#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows = 3, cols = 4;
  int **a = (int **)malloc(rows * sizeof(int *));
  for (int r = 0; r < rows; r++) {
    a[r] = (int *)malloc(cols * sizeof(int));
    for (int c = 0; c < cols; c++) {
      a[r][c] = 0;
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < rows; i++) {
    free(a[i]);
  }
  free(a);
}
