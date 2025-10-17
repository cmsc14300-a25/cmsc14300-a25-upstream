#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // characters
  char c = 123;
  char d = 'd';

  printf("The character associated with ASCII code %d is %c\n", c, c);
  printf("The ASCII code for %c is %d.\n", d, d);

  // string syntax
  char s[] = "Hello, world!";
  printf("s[12]: %c\n", s[12]);
  s[12] = '.';
  printf("s[12]: %c\n", s[12]);
  printf("s: %s\n", s);

  // more standard array syntax. Including just
  // to give you a better sense of representation, not
  // because you would write strings this way.
  char s1[] = {'H', 'e', 'l', 'l', 'o', '\0'};

  char *s2 = (char *)malloc(sizeof(char) * 3);
  // omitted malloc return value check for space.
  s2[0] = 'h';
  s2[1] = 'i';
  s2[2] = '\0';

  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);

  // The == performs pointer/reference equality
  // not value equality
  char *s3 = "abc";
  char s4[] = {'a', 'b', 'c', '\0'};
  char *s5 = s4;

  printf("s3: %s\n", s3);
  printf("s4: %s\n", s4);
  printf("s3 == s4: %d\n", s3 == s4);
  printf("s3: %s\n", s3);
  printf("s5: %s\n", s3);
  printf("s4 == s5: %d\n", s4 == s5);
  s5[0] = 'A';
  printf("s5[0]: %c\n", s5[0]);
  printf("s4: %s\n", s4);

  // string.h
  printf("s: %s\n", s);
  printf("strlen(s): %lu\n", strlen(s));
  printf("strcmp(\"a\", \"b\"): %d\n", strcmp("a", "b"));
}
