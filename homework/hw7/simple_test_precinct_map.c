#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "precinct_map.h"

int cmp(void *elem1, void *elem2) {
  char *op1 = *((char **) elem1);
  char *op2 = *((char **) elem2);
  printf("Comparing %s and %s\n", op1, op2);
  return strcmp(op1, op2);
}


int main() {
  precinct_map_t *pm = mk_pm();
  if (pm == NULL) {
    fprintf(stderr, "It appears that mk_pm has not been implemented\n");
    exit(1);
  }

  char *test_names[] = {"red",
			"blue",
			"green",
			"erd",
			"der",
  };
  int num_test_names = sizeof(test_names)/sizeof(char *);
  precinct_t *test_precincts[num_test_names];
  for (unsigned int i = 0; i < num_test_names; i++) {
    test_precincts[i] = mk_precinct(test_names[i]);
    if (test_precincts[i] == NULL) {
      fprintf(stderr, "It appears that mk_precinct has not been implemented\n");
      free_pm(pm);
      exit(1);      
    }
  }

  precinct_t *p = NULL;
  
  // test lookup on empty map
  for (int i=0; i <num_test_names; i++) {
    p = lookup_pm(pm, test_names[i]);
    assert(p == NULL);
  }

  for (int i=0; i <num_test_names; i++) {
    add_precinct_pm(pm, test_precincts[i]);
  }

  for (int i=0; i <num_test_names; i++) {
    p = lookup_pm(pm, test_names[i]);
    assert(p == test_precincts[i]);
  }
  
  // not in map that has some precincts.
  p = lookup_pm(pm, "dre");
  assert(p == NULL);

  int num_names = get_num_entries_pm(pm);
  assert(num_names == num_test_names);

  char *names[num_names];
  get_names_pm(pm, names, num_names);
  qsort(names, num_names, sizeof(*names), (int (*)(const void *, const void *)) cmp);
  printf("The precinct names...\n");
  for (int i=0; i < num_names; i++) {
    printf("  %s\n", names[i]);
  }

  free_pm(pm);
}

