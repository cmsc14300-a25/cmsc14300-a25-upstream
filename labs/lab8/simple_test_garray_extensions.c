#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "growable_array.h"

/* parse_arguments: parse the command-line arguments */
bool parse_arguments(int argc, char *argv[], bool *check_basic,
                     bool *check_print, bool *check_foreach, bool *check_foreach_data) {
  int opt;
  char *usage = ("Usage: %s [-b] [-p] [-f] [-e] [-h]");

  *check_basic = false;
  *check_print = false;
  *check_foreach = false;
  *check_foreach_data = false;  
  
  // Parse the arguments
  while ((opt = getopt(argc, argv, "bpfeh")) != -1) {
    switch (opt) { 
      case 'h':
        printf(usage, argv[0]);
        printf("\n");
        exit(0);
      case 'b':
        *check_basic = true;
        break;         
      case 'p':
        *check_print = true;
        break;
      case 'f':
        *check_foreach = true;
        break;
      case 'e':
        *check_foreach_data = true;
        break;

      default:
        fprintf(stderr, usage, argv[0]);
        return false;
    }
  }
  return true;
}

/* free a string */
void free_str(void *arg) {
  char *s = arg;
  if (s != NULL) { free(s); }
}

   
/* print a string with colons */
void print_str(void *arg) {
  char *s = arg;
  if (s == NULL) {
    printf("NULL\n");
  } else {
    printf(":%s:\n", s);
  }
}

/* print an integer from a pointer */
void print_int(void *arg) {
  int val = *((int *) arg);
  printf("%d\n", val);

}

/* increment an integer by one via a pointer */
void add_one_in_place(void *arg) {
  int *val_ptr = (int *) arg;
  *val_ptr = *val_ptr + 1;
}

/* update an integer by adding a constant via a pointer */
void add_const(void *arg1, void *arg2) {
    int *op1 = (int *) arg1;
    int *op2 = (int *) arg2;    
    *op1 = *op1 + *op2;
}

/* basic test: create a growable array, add some values,
 * print the contents of the array, and then free it
 */
void basic(bool call_print) {
  // make a growable array
  garray_t *sample = mk_garray(4, free_str);
  
  // fill it
  char *vals[] = {"AAA", "BBB", "CCC", "DDD",
                  "EEE", "FFF", "EEE", "GGG",
                  "", "Z"};
  int num_vals = sizeof(vals) / sizeof(char *);
  for (unsigned int i = 0; i < num_vals; i++) {
    garray_append(sample, strdup(vals[i]));
  }

  if (call_print) {
    printf("Print the array of strings...\n");
    garray_print(sample, print_str);
  }

  garray_free(sample);
}

/* foreach test: construct a growable array of pointers to integers
 *   print the contents of the array, then apply an increment function
 *   to every element and then print the results
 */
void foreach() {
  /* test empty growable array with foreach */
  garray_t *empty = mk_garray(2, NULL);
  garray_foreach(empty, add_one_in_place);
  assert(garray_get_length(empty) == 0);

  /* test one element growable array with foreach */
  garray_t *one = mk_garray(2, NULL);
  int val = 10;
  garray_append(one, &val);
  garray_foreach(one, add_one_in_place);
  assert(garray_get_length(one) == 1);
  int extracted_val = *((int *) garray_get_val(one, 0));
  assert(extracted_val == 11);


  /* test foreach with a growable value with multiple values */
  int some_vals[] = {1, 2, 3, 4, 5, 6};
  garray_t *int_sample = mk_garray(3, NULL);
  for (unsigned int i = 0; i < 6; i++) {
    garray_append(int_sample, &some_vals[i]);
  }

  garray_foreach(int_sample, add_one_in_place);

  int expected[] = {2, 3, 4, 5, 6, 7};
  for (unsigned int i = 0; i < 6; i++) {
    int val = * ((int *) garray_get_val(int_sample, i));
    assert(val == expected[i]);
  }

  garray_free(int_sample);

  
}


/* foreach with data test: construct a growable array of pointers to integers
 *   print the contents of the array, then apply a function that adds
 *   a constant (supplied as second argument to every element and
 *   then print the results
 */
void foreach_data() {
  int c = 7;

  /* test empty growable array with foreach */
  garray_t *empty = mk_garray(2, NULL);
  garray_foreach_with_data(empty, add_const, (void *)&c);
  assert(garray_get_length(empty) == 0);
  garray_free(empty);  

  /* test one element growable array with foreach */
  garray_t *one = mk_garray(2, NULL);
  int val = 10;
  garray_append(one, &val);
  garray_foreach_with_data(one, add_const, (void *)&c);
  assert(garray_get_length(one) == 1);
  int extracted_val = *((int *) garray_get_val(one, 0));
  assert(extracted_val == 17);
  garray_free(one);

  /* test element growable array with multiple elements with foreach_with_data */
  int some_vals[] = {1, 2, 3, 4, 5, 6};
  garray_t *int_sample = mk_garray(3, NULL);
  for (unsigned int i = 0; i < 6; i++) {
    garray_append(int_sample, &some_vals[i]);
  }

  garray_foreach_with_data(int_sample, add_const, (void *) &c);

  int expected[] = {8, 9, 10, 11, 12, 13};
  for (unsigned int i = 0; i < 6; i++) {
    int val = * ((int *) garray_get_val(int_sample, i));
    assert(val == expected[i]);
  }

  garray_free(int_sample);

}


int main(int argc, char* argv[]) {
  bool check_basic;
  bool check_print;
  bool check_foreach;
  bool check_foreach_data;  
  
  if (!parse_arguments(argc, argv, &check_basic, &check_print, &check_foreach, &check_foreach_data)) {
    return 0;
  }

  if (check_basic) { basic(false); };
  if (check_print) { basic(true); };
  if (check_foreach) { foreach(); }
  if (check_foreach_data) { foreach_data(); }  
}
