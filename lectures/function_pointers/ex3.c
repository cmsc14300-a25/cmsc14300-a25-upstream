#include <stdio.h>

typedef void (*print_func_t)(char *);

void print_array(char **array, int len, print_func_t print_fn) {
  for (unsigned int i = 0; i < len; i++) {
    print_fn(array[i]);
  }
}


void print_str(char *s) {
  printf("%s\n", s);
}

void print_str_colons(char *s) {
  printf(":%s:\n", s);
}



int main() {
  char *strs[] = {"aaa", "bbb", "ccc"};

  printf("printing with print_str...\n");
  print_array(strs, 3, print_str);  

  printf("printing with print_str colons...\n");
  print_array(strs, 3, print_str_colons);  
}
	   
