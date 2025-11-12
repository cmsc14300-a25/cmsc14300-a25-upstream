/*
 * CMSC 14300
 * Autumn 2025
 * Homework #6: Growable array header file
 *
 * API for growable arrays with (void *) elements.
 *
 * You may NOT modify this file.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct growable_array garray_t;

/* mk_garray: construct a growable array using the specified
 *   size as the initial number of slots allocated (but not filled).
 *
 * initial_size: the numer of array slots to be allocated.
 *
 * Returns: a pointer to a growable array
 */
 garray_t *mk_garray(unsigned int initial_size);

/* garray_get_length: get the number of elements in the array
 *
 * garray: the growable array of interest
 *
 * Returns: the number of elements in the growable array
 */
unsigned int garray_get_length( garray_t *garray);

/* garray_append: add a value to the current end of the
 *   growable array.
 *
 * garray: the growable array of interest
 * val: the value to add.
 *
 */
void garray_append( garray_t *garray, void *val);

/* garray_pop: removes the last element from the array and returns it.  The
 *   growable array must have at least one element.
 *
 * garray: the growable array of interest
 *
 * Returns: the last element in the array.
 */
void *garray_pop( garray_t *garray);

/* garray_get_val: get the value at the specified index.  The index
 *   must be less than the current number of elements in the growable
 *   array.
 *
 * garray: the growable array of interest
 * idx: the index of interest
 *
 * Returns: the value at the specified index.*
 */
void *garray_get_val( garray_t *garray, unsigned int idx);

/* garray_set_val: set the value at the specified index to the specified value.
 *   The index must be less than the current number of elements
 *   in the growable array.
 *
 * garray: the growable array of interest
 * idx: the index of interest
 * val: the value to add
 *
 * Returns: nothing
 */
void garray_set_val( garray_t *garray, unsigned int idx, void *val);

/* garray_free: frees the space associated with the growable array
 *   infrastructure. This function does not free the elements.
 */
void garray_free( garray_t *garray);


void garray_print(garray_t *garray, void (*print_fn)(void *));

void garray_apply_to_element(garray_t *garray, void *(*element_fn)(void *));

void garray_free_with_elements(garray_t *garray, void (*element_free_fn)(void *));

garray_t* garray_map(garray_t* garray, 
                     void* (*element_fn)(void*, void*),
                     void* extra_arg);