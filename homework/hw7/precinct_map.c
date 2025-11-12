/*
 * CMSC 14300
 * Autumn 2025
 * Homework #7: Precinct map implementation
 *
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "precinct.h"
#include "precinct_map.h"

// Table size will always be a power of two
#define INIT_SIZE 4
#define MULTIPLIER 2

typedef struct bucket {
  char *name;
  uint64_t hash_val_for_name;
  precinct_t *precinct;
  struct bucket *next;
} bucket_t;

struct precinct_map {
  struct bucket **table;
  int num_buckets;
  int num_entries;
};

/**** Helpers ****/
/**** Provided Helper ****/

/* hash: implements the Fowler-Noll-Vo hash function.
 *   This code is a direct translation of the pseudo-code
 *   from this Wikipedia page:
 *   https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function.
 *  
 * char *name - the string to hash
 *
 * Returns: FNV hash value.
 */
uint64_t hash(char *name) {
  uint64_t hash = 0xcbf29ce484222325;
  uint64_t FNV_prime = 0x100000001b3;

  for (; *name != '\0'; name++) {
    uint8_t byte_of_data = *name;
    hash = hash * FNV_prime;
    hash = hash ^ byte_of_data;
  }
  return hash;
}


// YOUR HELPERS GO HERE...


/********** Precinct Map API **********/

/* mk_pm -- see precinct.h for the header comment */
precinct_map_t *mk_pm(void) {
  // TODO: complete this function
  // Replace NULL with an appropriate return value
  return NULL;

}


/* free_pm -- see precinct.h for the header comment */
void free_pm(precinct_map_t *pm) {
  // TODO: complete this function
}


/* lookup_pm -- see precinct.h for the header comment */
precinct_t *lookup_pm(precinct_map_t *pm, char *name) {
  // TODO: complete this function
  // Replace NULL with an appropriate return value
  return NULL;
}


/* add_precinct_pm -- see precinct.h for the header comment */
bool add_precinct_pm(precinct_map_t *pm, precinct_t *precinct) {
  // TODO: Complete this function
  // Replace false with an appropriate return value
  return false;
}


/* get_num_entries -- see precinct.h for the header comment */
unsigned int get_num_entries_pm(precinct_map_t *pm) {
  // TODO: Complete this function
  // Replace 0u with an appropriate return value
  return 0u;
}


/* get_names_pm -- see precinct.h for the header comment */
void get_names_pm(precinct_map_t *pm, char *result[], int len) {
  // TODO: Complete this function
}
   
