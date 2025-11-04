/*
 * CMSC 14300
 * Autumn 2025
 * Lab #6: Growable array implementation
 *
 * You will modify this file.
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

// Put any helper functions here...

/***** API implementation starts here *****/

/* mk_garray -- see growable_array.h for the header comment */
garray_t *mk_garray(unsigned int initial_size) {
  // TODO: complete this function and replace the return
  // value with a suitable value
  return NULL;
}

/* garray_free -- see growable_array.h for the header comment */
void garray_free(garray_t *garray) {
  // TODO: complete this function
}

/* garray_get_length -- see growable_array.h for the header comment */
unsigned int garray_get_length(garray_t *garray) {
  assert(garray != NULL);
  
  // TODO: complete this function and replace the return
  // value with a suitable value
  return 0;
}

/* garray_append -- see growable_array.h for the header comment */
void garray_append(garray_t *garray, void *val) {
  // TODO: complete this function
}

/* garray_pop -- see growable_array.h for the header comment */
void *garray_pop(garray_t *garray) {
  assert(garray != NULL);
  // there is at least one element in the array
  assert(garray->num_vals > 0);

  // TODO: complete this function and replace the return
  // value with a suitable value
  return NULL;
}

/* garray_get_val -- see growable_array.h for the header comment */
void *garray_get_val(garray_t *garray, unsigned int idx) {
  assert(garray != NULL);

  // TODO: complete this function and replace the return
  // value with a suitable value
  return NULL;
}

/* garray_set_val -- see growable_array.h for the header comment */
void garray_set_val(garray_t *garray, unsigned int idx, void *val) {
  assert(garray != NULL);

  // TODO: complete this function
}
