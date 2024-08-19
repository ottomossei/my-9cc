#include <ctype.h>
#include <stdio.h>

int main() {
  char *p = "3 cats";
  while (*p) {
    printf("[%s]\n", p);
    if (isspace(*p)) {
      printf("space is contained\n");
    }
    if (isdigit(*p)) {
      printf("digit is contained\n");
    }
    p++;
  }
}
