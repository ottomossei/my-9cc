#include <stdio.h>
#include <stdlib.h>

int main() {
  char *p = "cat";
  int count = 1;
  while (*p) {
    printf("%d\n", count);
    printf("%s\n", p);  // cat at t
    p++;
    count++;
  }
}
