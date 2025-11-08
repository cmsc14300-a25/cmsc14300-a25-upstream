#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// recursively swap values bottom-up
void sift_up(int heap[], int index) {
  if (index == 0) {
    return;
  }

  int parent = (index - 1) / 2;
  if (heap[index] < heap[parent]) {
    swap(&heap[index], &heap[parent]);
    sift_up(heap, parent);
  }
}

// recursively swap values top-down
void sift_down(int heap[], int size, int index) {
  
  int min_index = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  // if there is a left child consider it
  if (left < size) {
    if (heap[left] < heap[min_index]) {
      min_index = left;
    }
  }

  // if there is a right child consider it
  if (right < size) {
    if (heap[right] < heap[min_index]) {
      min_index = right;
    }
  }

  // swap, if one of the children is smaller.
  if (min_index != index) {
    swap(&heap[index], &heap[min_index]);
    sift_down(heap, size, min_index);
  }
}

