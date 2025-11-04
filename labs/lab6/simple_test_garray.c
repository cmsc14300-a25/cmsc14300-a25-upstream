#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "growable_array.h"

/* parse_arguments: parse the command-line arguments */
bool parse_arguments(int argc, char *argv[], bool *check_basic,
                     bool *check_append,
                     bool *check_pop) {
  int opt;
  char *usage = ("Usage: %s [-b] [-a] [-p] [-h]");

  *check_basic = false;
  *check_append = false;
  *check_pop = 0;
  
  // Parse the arguments
  while ((opt = getopt(argc, argv, "abph")) != -1) {
    switch (opt) { 
      case 'h':
        printf(usage, argv[0]);
        printf("\n");
        exit(0);
      case 'a':
        *check_append = true;
        break;              
      case 'b':
        *check_basic = true;
        break;         
      case 'p':
        *check_pop = true;
        break;
      default:
        fprintf(stderr, usage, argv[0]);
        return false;
    }
  }
  return true;
}

void test_basic() {
  garray_t* garray = mk_garray(5);
  garray_free(garray);
}

garray_t* mk_sample(char *vals[], unsigned int num_vals,
                    unsigned int initial_size) {
  garray_t* garray = mk_garray(initial_size);

  for (unsigned int i = 0; i < num_vals; i++) {
    // this function expects a pointer (of type void *) to a value
    garray_append(garray, (void*)vals[i]);
  }

  return garray;
}

void test_append_and_get_and_set(char *vals[], unsigned int num_vals,
                              unsigned int initial_size, bool test_set) {
  garray_t* garray = mk_sample(vals, num_vals, initial_size);

  for (unsigned int i = 0; i < num_vals; i++) {
    // this function expects a pointer (of type void *) to a value
    char *val_ptr = (char *) garray_get_val(garray, i);
    assert(strcmp(val_ptr, vals[i]) == 0);;
  }

  if (test_set) {
     for (unsigned int i = 0; i < num_vals; i++) {
        garray_set_val(garray, i, vals[num_vals - 1 - i]);
    } 

    for (unsigned int i = 0; i < num_vals; i++) {
      // this function expects a pointer (of type void *) to a value
      char *val_ptr = (char *)garray_get_val(garray, i);
      assert(strcmp(val_ptr, vals[num_vals - 1 - i]) == 0);
    }
  }

  garray_free(garray);
}

void test_pop(char *vals[], unsigned int num_vals,
              unsigned int initial_size) {
  garray_t* garray = mk_sample(vals, num_vals, initial_size);

  // the values should come out in reverse order
  for (unsigned int i = 0; i < num_vals; i++) {
    char *val = garray_pop(garray);
    assert(strcmp(val, vals[num_vals - i - 1]) == 0);
  }
  assert(garray_get_length(garray) == 0);

  garray_free(garray);
}

int main(int argc, char* argv[]) {
  bool check_basic;
  bool check_append;
  bool check_pop;
  if (!parse_arguments(argc, argv, &check_basic, &check_append, &check_pop)) {
    return 0;
  }

  if (check_basic) {
    printf("Testing create and free\n");
    test_basic();
  }

  char *vals[] = {"AAA", "BBB", "CCC", "DDD",
                  "EEE", "FFF", "EEE", "GGG"};
  int num_vals = sizeof(vals) / sizeof(char *);
  int sizes[] = {10, 5, 3, 8};
  int num_sizes = 4;

  if (check_append) {
    printf("Testing create, append, get, set, and free\n");
    for (unsigned int i = 0; i < num_sizes; i++) {
      printf("trying initial size of %u\n", sizes[i]);
      test_append_and_get_and_set(vals, num_vals, sizes[i], false);
      test_append_and_get_and_set(vals, num_vals, sizes[i], true); 
    } 
  }

  if (check_pop) {
    for (unsigned int i = 0; i < num_sizes; i++) {
      printf("trying pop with an initial size of %u\n", sizes[i]);
      test_pop(vals, num_vals, sizes[i]);
    } 
  }
}
