#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"

struct intlist {
   int val;
   intlist_t *next;
};

// Make an intlist element
intlist_t *mk_intlist(int val, intlist_t *rest) {
    intlist_t *lst = (intlist_t*)malloc(sizeof(intlist_t));
    if (lst == NULL) {
        fprintf(stderr, "mk_intlist: Unable to allocate\n");
        exit(1);
    }

    lst->val = val;
    lst->next = rest;
    return lst;
}

// Determine whether or not the list is empty
int is_empty(intlist_t *lst) {
    return lst == NULL;
}

// Get the first value in the list
int first(intlist_t *lst) {
    if (lst == NULL) {
        fprintf(stderr, "first: lst is NULL\n");
        exit(1);
    }

    return lst->val;
}

// Get the list except for the first element
intlist_t *rest(intlist_t *lst) {
    if (lst == NULL) {
        fprintf(stderr, "rest: lst is NULL\n");
        exit(1);
    }

    return lst->next;
}

// Free all elements in a list
void free_intlist_rec(intlist_t *lst) {
  if (lst == NULL) {
    return;
  }

  free_intlist_rec(rest(lst));
  free(lst);
}


void free_intlist_iter(intlist_t *lst) {
    intlist_t *next;

    while(lst != NULL) {
        next = lst->next;
        free(lst);
        lst = next;
    }
}


// add up the values in a list -- recursive implementation
int sum_list_rec(intlist_t *lst) {
  if (is_empty(lst)) {
    return 0;
  }

  return first(lst) + sum_list_rec(rest(lst));
}


// add up the values in a list -- iterative implementation
int sum_list_iter(intlist_t *lst) {
  int rv = 0;
  while (lst != NULL) {
    rv += lst->val;
    lst = lst->next;
  }
  return rv;
}

// add up the values in a list with a dummy head node.
int sum_list_dummy(intlist_t *lst) {
  // what changes are needed?

  int rv = 0;
  while (lst != NULL) {
    rv += lst->val;
    lst = lst->next;
  }
  return rv;
}


// get the last value in the list
int get_last_val(intlist_t *lst) {
   assert(lst != NULL);

   // stop when you get to the last node.
   while (lst->next != NULL) {
       lst = lst->next;
   }

   return lst->val;
}


// remove the first element from the list
intlist_t *remove_front_intlist(intlist_t *lst) {
  assert(lst != NULL);

  // keep track of the rest of the list
  intlist_t *rest = lst->next;
    
  // free the space for the first element in the list
  free(lst);

  // return the rest of the list
  return rest;
}


// This version assumes the list has a dummy node
void remove_front_with_dummy(intlist_t *lst) {
  // there needs to be at least one element in the list
  assert(lst != NULL);
  assert(lst->next != NULL);    

  intlist_t *orig_first = lst->next;
  lst->next = lst->next->next;
  free(orig_first);
}

// remove val from regular list if it occurs
intlist_t *remove_val(intlist_t *lst, int val) {
  intlist_t *prev = NULL;
  intlist_t *curr = lst;

  while ((curr != NULL) && (curr->val != val)) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL) {
    // did not find it.  Return the head of the list.
    return lst;
  } else if (prev == NULL) {
    // val is the first value in the list
    // its neighbor is now the new head of the list
    lst = curr->next;
  } else {
    // val is past the first node
    // fix the pointers
    prev->next = curr->next;
  }
  
  free(curr);
  return lst;
}

int main() {

  intlist_t *lst = mk_intlist(10, 
                     mk_intlist(20, 
                       mk_intlist(30, 
                        mk_intlist(40, NULL))));
  printf("Empty? %s\n", is_empty(lst) ? "Yes" : "No");

  printf("Sum elements -- rec: %d\titer: %d\n", 
         sum_list_rec(lst),
         sum_list_iter(lst));

  printf("Last element: %d\n", get_last_val(lst));

  lst = remove_front_intlist(lst);
  printf("Sum elements after remove front: %d\n", 
         sum_list_iter(lst));  

  int vals_to_remove[] = {30, 40, 10, 20};
  for (unsigned int i = 0; i < 4; i++) {
    lst = remove_val(lst, vals_to_remove[i]);
     printf("Sum elements after removing %d: %d\n", 
            vals_to_remove[i], sum_list_iter(lst));
  }  
  printf("Empty? %s\n", is_empty(lst) ? "Yes" : "No");

  // Free the list
  free_intlist_rec(lst);

  // Rebuild the list and then check the interative free function
  intlist_t *lst2 = mk_intlist(10, 
                     mk_intlist(20, 
                       mk_intlist(30, NULL)));
  free_intlist_iter(lst2);  
}

