/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Growable array implementation
 *
 * You may NOT modify this file.
 */

#include "growable_array.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MULTIPLIER 2

struct growable_array {
  unsigned int num_vals;
  unsigned int capacity;
  void** data;
};

/***** Helper functions *****/
/* get_space: allocate/realloc space and check the return value
 *
 * ptr: NULL or pointer to the space to be realloced.
 * num_bytes: the number of bytes to allocate
 * func_name: name of the function calling get_space
 *
 * Returns: pointer to space allocated
 */
static void *get_space(void *ptr, size_t num_bytes, char *func_name) {
  void *space;

  // realloc calls malloc when ptr is NULL
  space = realloc(ptr, num_bytes);
  if (space == NULL) {
    fprintf(stderr, "Ran out of space in %s\n", func_name);
    exit(1);
  }
  return space;
}

/* fill_with_null: a helper function that fills the specified
 *   space with NULL from the specified lower bound up to
 *   the specified upper bound.
 *
 * data: the array to modify
 * lb: the lower bound (inclusive)
 * ub: the upper bound (non-inclusive)
 *
 * Returns: nothing
 */
static void fill_with_null(void** data, unsigned int lb, unsigned int ub) {
  for (unsigned int i = lb; i < ub; i++) {
    data[i] = NULL;
  }
}

/***** API implementation starts here *****/

/* mk_garray -- see growable_array.h for the header comment */
garray_t *mk_garray(unsigned int initial_size) {
  assert(initial_size > 0);
  garray_t *garray = (garray_t*)get_space(NULL, sizeof(garray_t), "mk_garray");
  garray->capacity = initial_size;
  garray->num_vals = 0;
  garray->data =
      (void**)get_space(NULL, initial_size * sizeof(void*), "mk_garray");
  fill_with_null(garray->data, 0, initial_size);
  return garray;
}

/* garray_free -- see growable_array.h for the header comment */
void garray_free(garray_t *garray) {
  // do not free the elements.
  free(garray->data);
  free(garray);
}

/* garray_get_length -- see growable_array.h for the header comment */
unsigned int garray_get_length(garray_t *garray) {
  assert(garray != NULL);
  return garray->num_vals;
}

/* garray_append -- see growable_array.h for the header comment */
void garray_append(garray_t *garray, void *val) {
  if (garray->num_vals == garray->capacity) {
    int new_num_slots = garray->capacity * MULTIPLIER;
    garray->data = (void**)get_space(
        garray->data, new_num_slots * sizeof(void*), "garray_append");
    fill_with_null(garray->data, garray->num_vals, new_num_slots);
    garray->capacity = new_num_slots;
  }
  // now there is enough space
  garray->data[garray->num_vals] = val;
  garray->num_vals++;
}

/* garray_pop -- see growable_array.h for the header comment */
void *garray_pop(garray_t *garray) {
  assert(garray != NULL);
  // there is at least one element in the array
  assert(garray->num_vals > 0);
  garray->num_vals--;
  void *rv = garray->data[garray->num_vals];
  // don't leave the pointer laying around
  garray->data[garray->num_vals] = NULL;

  // someday...add code to shrink the array 
  // when the number of elements in the array is
  // substantially smaller than the capacity.

  return rv;
}

/* garray_get_val -- see growable_array.h for the header comment */
void *garray_get_val(garray_t *garray, unsigned int idx) {
  assert(garray != NULL);
  // idx must be valid.
  assert(idx < garray->num_vals);
  return garray->data[idx];
}

/* garray_set_val -- see growable_array.h for the header comment */
void garray_set_val(garray_t *garray, unsigned int idx, void *val) {
  assert(garray != NULL);
  // idx must be valid.
  assert(idx < garray->num_vals);
  garray->data[idx] = val;
}
